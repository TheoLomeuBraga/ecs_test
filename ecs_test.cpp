
#include <iostream>
#include "ecs_entity.h"
#include "ecs_name.h"


//compile comand
//g++ ecs_test.cpp -o ecs_test -I./ecs -I./ecs/ecs_components
int main() {
    
    std::cout << "Hello World!" << std::endl;

    size_t entity = new_entity();
    std::cout << "entity id " << entity << std::endl;



    return 0;
}