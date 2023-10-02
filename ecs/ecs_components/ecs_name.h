#pragma once 

#include "ecs_entity.h"
#include <vector>
#include <string>
#include <map>
#include <set>

std::map<size_t,std::string> names_map;

void add_name(size_t id,std::any data){
    names_map.insert(std::pair<size_t,std::string>(id,std::any_cast<std::string>(data)));
}

bool have_name(size_t id){
    if(names_map.find(id) != names_map.end()){
        return true;
    }
    return false;
}

void run_name(size_t id){}

void run_names(){}

void remove_name (size_t id){
    names_map.erase(id);
}

void register_name_component(){
    ecs_components_registerd.insert(std::pair<std::string,struct ecs_component>("name",{add_name,have_name,run_name,run_names,remove_name}));
}

std::string* get_name(size_t id){
    return &names_map[id];
}
