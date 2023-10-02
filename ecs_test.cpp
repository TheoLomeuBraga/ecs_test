
#include <iostream>
#include "ecs_entity.h"
#include "ecs_name.h"


//compile comand
//g++ ecs_test.cpp -o ecs_test -I./ecs -I./ecs/ecs_components
int main() {

    std::cout << "Hello World!" << std::endl;

    size_t entity = new_entity();
    std::cout << "entity id " << entity << std::endl;

    register_name_component();
    add_component(entity,"name",std::string("theo"));
    std::cout << "entity name " << get_name(entity) << std::endl;

    remove_component(entity,"name");
    std::cout << "entity have name " << have_component(entity,"name") << std::endl;

    return 0;
}