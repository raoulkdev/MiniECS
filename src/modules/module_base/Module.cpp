//
// Created by Raoul Kaleba on 4/15/2025.
//

// Imports
#include "Module.h"
#include <iostream>

int MiniECS::Module::moduleId = 0;

MiniECS::Module::Module(const ModuleType setType)
{
    type = setType;

    switch (type)
    {
        case ModuleType::ModuleBase:
            moduleTypeName =  "ModuleBase";
            break;
        case ModuleType::Transform:
            moduleTypeName = "Transform";
            break;
        case ModuleType::Renderer:
            moduleTypeName =  "Renderer";
            break;
        default:
            moduleTypeName = "Unknown";
            break;
    }

    moduleId++;
    std::cout << "Added " << moduleTypeName << ", Module ID: " << moduleId << "\n";
}

MiniECS::Module::~Module()
{
    // Add remove module function
    std::cout << "Removed " << moduleTypeName << ", ID: " << moduleId << "\n";
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

