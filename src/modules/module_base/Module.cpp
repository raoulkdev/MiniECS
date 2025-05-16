// Imports
#include <iostream>
#include "Module.h"

// Constructor
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

// Destructor
MiniECS::Module::~Module()
{
    // Add remove module function
    std::cout << "Removed " << moduleTypeName << "\n";
}

// Return Module type string
std::string MiniECS::Module::getTypeName()
{
    return moduleTypeName;
}

// Return Module type enum value
MiniECS::ModuleType MiniECS::Module::getType()
{
    return type;
}


// Game loop/lifetime
void MiniECS::Module::start()
{
    std::cout << "Start / Start module\n";
}

