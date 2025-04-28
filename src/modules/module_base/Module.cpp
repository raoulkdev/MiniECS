//
// Created by Raoul Kaleba on 4/15/2025.
//

// Imports
#include "Module.h"
#include <iostream>

int MiniECS::Module::moduleId = 0;

MiniECS::Module::Module(const std::string& type)
{
    moduleType = type;
    moduleId++;
    std::cout << "Added " << moduleType << ", Module ID: " << moduleId << "\n";
}

MiniECS::Module::~Module()
{
    // Add remove module function
    std::cout << "Removed " << moduleType << ", ID: " << moduleId << "\n";
}

int MiniECS::Module::getId()
{
    return moduleId;
}


// Default module update
void MiniECS::Module::start()
{
    std::cout << "Start / Start module\n";
}

