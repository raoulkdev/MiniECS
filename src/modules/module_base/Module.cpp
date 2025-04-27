//
// Created by Raoul Kaleba on 4/15/2025.
//

// Imports
#include "Module.h"
#include <iostream>

int Module::moduleId = 0;

Module::Module(const std::string& type)
{
    moduleType = type;
    moduleId++;
    std::cout << "Added " << moduleType << ", Module ID: " << moduleId << "\n";
}

Module::~Module()
{
    // Add remove module function
    std::cout << "Removed " << moduleType << ", ID: " << moduleId << "\n";
}

int Module::getId()
{
    return moduleId;
}


// Default module update
void Module::start()
{
    std::cout << "Start / Start module\n";
}

