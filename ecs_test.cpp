
#include <iostream>
#include "ecs.h"
#include "ecs_name.h"


//compile comand
//g++ ecs_test.cpp -o ecs_test -I./ecs -I./ecs/ecs_systems
//./ecs_test

int main() {

    //register components
    register_name_component();

    //create entity
    entity ent = new_entity();
    std::cout << "entity id " << ent << std::endl;

    //add name
    add_component(ent,"name",std::string("theo"));
    std::cout << "entity name " << *get_name(ent) << std::endl;
    std::cout << "entity have name " << have_component(ent,"name") << std::endl;

    //change name
    names_map[ent] = "ricardo";
    std::cout << "entity name " << *get_name(ent) << std::endl;

    //remove name
    remove_component(ent,"name");
    std::cout << "entity have name " << have_component(ent,"name") << std::endl;

    delete_entity(ent);

    return 0;
}