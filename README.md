### ecs_test

## Overview

This README provides documentation to an test library called ecs_test, a C++ library designed for creating and managing entities with associated components. The library allows you to define and manipulate entities and their components dynamically.

## Getting Started

To use this library, follow these steps:
1. Include the Library: Include the necessary headers at the beginning of your C++ files where you plan to use the ECS system.
    
    ```cpp
    #include "ecs_entity.h"
    #include "ecs_name.h"
    ```

2. Register Components: Register any custom components you want to use with the ECS system by calling their respective registration functions. For example:
    ```cpp
    // Example registration of a 'name' component
    register_name_component();
    ```

3. Register Components: Register any custom components you want to use with the ECS system by calling their respective registration functions. For example:
    ```cpp
    size_t entity = new_entity();
    ```

    Adding Components: Add components to entities using the `add_component` function. Provide the entity's ID, the component's name, and the component's data.
    ```cpp
    add_component(entity, "name", std::string("theo"));
    ```

4. Removing Components: Remove components from entities using the remove_component function:
    ```cpp
    remove_component(entity, "name");
    ```

5. Checking Component Existence: You can check if an entity has a specific component using the `have_component` function:
    ```cpp
    bool hasName = have_component(entity, "name");
    ```

6. Running Components: Use the `run_components` function to run all registered components:
    ```cpp
    run_components();
    ```

7. Cleaning Up Entities: To delete entities and their associated components, use the delete_entity function. It will remove all components associated with the entity and free its ID.
    ```cpp
    delete_entity(entity);
    ```

## Custom Components

To create custom components, follow these steps:

1. Define the component structure with the necessary functions. For example:

    ```cpp
    struct ecs_component
    {
        void (*add)(size_t, std::any);
        bool (*have)(size_t);
        void (*run)(size_t);
        void (*run_components)();
        void (*remove)(size_t);
    };
    ```

2. Implement the component functions. These functions should manipulate the component's data associated with entities.

3. Register the custom component using the `ecs_components_registerd` map and the `register_name_component` function as an example.

## Custom Component Example
```cpp
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

size_t search_entity_by_name(std::string name){
    for(std::pair<size_t,std::string> p : names_map){
        if(p.second == name){
            return p.first;
        }
    }
    return 0;
}

```

## Usage Example
```cpp

#include <iostream>
#include "ecs_entity.h"
#include "ecs_name.h"


//compile comand
//g++ ecs_test.cpp -o ecs_test -I./ecs -I./ecs/ecs_components
int main() {

    //register components
    register_name_component();

    //create entity
    size_t entity = new_entity();
    std::cout << "entity id " << entity << std::endl;

    //add name
    add_component(entity,"name",std::string("theo"));
    std::cout << "entity name " << *get_name(entity) << std::endl;
    std::cout << "entity have name " << have_component(entity,"name") << std::endl;

    //change name
    *get_name(entity) = std::string("ricardo");
    std::cout << "entity name " << *get_name(entity) << std::endl;

    //remove name
    remove_component(entity,"name");
    std::cout << "entity have name " << have_component(entity,"name") << std::endl;

    return 0;
}
```