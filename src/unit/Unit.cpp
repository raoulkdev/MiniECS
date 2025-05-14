//
// Created by Raoul Kaleba on 4/15/2025.
//

// Imports
#include "Unit.h"
#include "../modules/module_base/Module.h"

// Constructor
MiniECS::Unit::Unit(std::string newName)
{
    name = std::move(newName);
    std::cout << "Constructed unit, name: " << name << "\n";
}

// Destructor
MiniECS::Unit::~Unit()
{
    std::cout << "Destructed unit, name: " << name << "\n";
}

// Add Module
void MiniECS::Unit::addModule(std::unique_ptr<Module> moduleToAdd)
{
    bool duplicateType = false;
    for (std::unique_ptr<Module>& module : modules)
    {
        if (module->getType() == moduleToAdd->getType())
        {
            duplicateType = true;
            std::cout << "Cannot add: " << module->getTypeName() << "to Unit because it already exsists!\n";
        }
    }
    if (!duplicateType)
    {
        modules.push_back(std::move(moduleToAdd));
    }
}

std::string MiniECS::Unit::getName() const
{
    return name;
}

std::vector<std::unique_ptr<MiniECS::Module>>& MiniECS::Unit::getModulesVector()
{
    return modules;
}

// Call all Module start functions
void MiniECS::Unit::callModuleStart() const
{
    for (const std::unique_ptr<Module> &sModule : modules)
    {
        sModule->start();
    }
}
