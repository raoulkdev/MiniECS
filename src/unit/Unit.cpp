//
// Created by Raoul Kaleba on 4/15/2025.
//
#include "Unit.h"
#include "../modules/module_base/Module.h"

// Constructor and Destructor
Unit::Unit(std::string newName)
{
    name = std::move(newName);
    std::cout << "Constructed unit, name: " << name << "\n";
}

Unit::~Unit()
{
    std::cout << "Destructed unit, name: " << name << "\n";
}

// Add Module
void Unit::addModule(std::unique_ptr<Module> module)
{
    modules.push_back(std::move(module));
}

// Call All Module Updates
void Unit::callModuleUpdate()
{
    for (const std::unique_ptr<Module> &module : modules)
    {
        module->update();
    }
}
