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