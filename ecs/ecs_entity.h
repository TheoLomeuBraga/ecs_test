#pragma once 

#include <vector>
#include <string>
#include <unordered_map>
#include <set>

struct ecs_component{

    void(*add)(size_t,void*);
    bool(*have)(size_t);

    void(*run)(size_t);

    void(*remove)(size_t);
    
};

std::unordered_map<std::string,struct ecs_component> ecs_components_registerd;

std::set<size_t> entityes_set = {};

size_t find_free_entity(){
    size_t i = 1;
    while(i < SIZE_MAX){
        if(entityes_set.find(i) == entityes_set.end()){
            return i;
        }
        i++;
    }
    return 0;
}

size_t new_entity(){
    size_t fe = find_free_entity();
    entityes_set.insert(fe);
    return fe;
}

void add_component(size_t entity,std::string component_name,void* arg){
    ecs_components_registerd[component_name].add(entity,arg);
}

void remove_component(size_t entity,std::string component_name){
    ecs_components_registerd[component_name].remove(entity);
}

void run_entity(size_t entity){
    for(std::pair<std::string,struct ecs_component> p : ecs_components_registerd){
        if(p.second.have(entity)){
            p.second.run(entity);
        }
    }
    entityes_set.erase(entity);
}

void delete_entity(size_t entity){
    for(std::pair<std::string,struct ecs_component> p : ecs_components_registerd){
        if(p.second.have(entity)){
            p.second.remove(entity);
        }
    }
    entityes_set.erase(entity);
}