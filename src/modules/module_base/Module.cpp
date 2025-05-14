//
// Created by Raoul Kaleba on 4/15/2025.
//

// Imports
#include "Module.h"
#include <iostream>

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

    std::cout << "Added " << moduleTypeName << "\n";
}

MiniECS::Module::~Module()
{
    // Add remove module function
    std::cout << "Removed " << moduleTypeName << "\n";
}

std::string MiniECS::Module::getTypeName()
{
    return moduleTypeName;
}

MiniECS::ModuleType MiniECS::Module::getType()
{
    return type;
}


// Default module update
void MiniECS::Module::start()
{
    std::cout << "Start / Start module\n";
}

