#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <any>

struct ecs_component
{

    void (*add)(size_t, std::any);
    bool (*have)(size_t);

    void (*run)(size_t);
    void (*run_components)();

    void (*remove)(size_t);
};

std::unordered_map<std::string, struct ecs_component> ecs_components_registerd;

std::set<size_t> entityes_set = {},free_entityes = {};
size_t next_entity_id = 1;

size_t find_free_entity()
{
    size_t i = 1;
    while (i < SIZE_MAX)
    {
        if (entityes_set.find(i) == entityes_set.end())
        {
            return i;
        }
        i++;
    }
    return 0;
}

size_t new_entity()
{
    if (!free_entityes.empty())
    {
        size_t id = *free_entityes.begin();
        free_entityes.erase(id);
        return id;
    }
    else
    {
        return next_entity_id++;
    }
}

void add_component(size_t entity, std::string component_name, std::any arg)
{
    ecs_components_registerd[component_name].add(entity, arg);
}

bool have_component(size_t entity, std::string component_name)
{
    if (ecs_components_registerd[component_name].have(entity))
    {
        return true;
    }
    return false;
}

void remove_component(size_t entity, std::string component_name)
{
    ecs_components_registerd[component_name].remove(entity);
}

void run_entity(size_t entity)
{
    for (std::pair<std::string, struct ecs_component> p : ecs_components_registerd)
    {
        if (p.second.have(entity))
        {
            p.second.run(entity);
        }
    }
}

void run_components()
{
    for (std::pair<std::string, struct ecs_component> p : ecs_components_registerd)
    {
        p.second.run_components();
    }
}

void delete_entity(size_t entity)
{
    free_entityes.insert(entity);
    for (std::pair<std::string, struct ecs_component> p : ecs_components_registerd)
    {
        if (p.second.have(entity))
        {
            p.second.remove(entity);
        }
    }
    entityes_set.erase(entity);
}

void clean_components()
{
    for(size_t i : entityes_set){
        delete_entity(i);
    }
}