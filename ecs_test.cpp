
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