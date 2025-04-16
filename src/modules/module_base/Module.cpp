//
// Created by Raoul Kaleba on 4/15/2025.
//

#include "Module.h"
#include <iostream>

// Constructor and Destructor
Module::Module(Unit &newOwner)
    : owner(&newOwner) {std::cout << "Constructed module, owner: " << &newOwner;}

Module::~Module()
{
}
