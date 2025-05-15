//
// Created by Raoul Kaleba on 4/15/2025.
//

// Imports
#include "Unit.h"
#include "../modules/module_base/Module.h"
#include "../modules/renderer/RendererModule.h"
#include "../modules/transform/TransformModule.h"

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
void MiniECS::Unit::addModule(ModuleType moduleType)
{
    bool duplicate = false;
    for (std::unique_ptr<Module>& module : modules)
    {
        if (module->getType() == moduleType)
        {
            duplicate = true;
            std::cout << "Module type already exsists, cannot add it!\n";
        }
    }
    if (!duplicate)
    {
        switch (moduleType)
        {
            case ModuleType::Renderer:
                modules.push_back(std::move(std::make_unique<RendererModule>(ModuleType::Renderer)));
                break;
            case ModuleType::Transform:
                modules.push_back(std::move(std::make_unique<TransformModule>(ModuleType::Transform)));
                break;
            default:
                std::cout << "Invalid Module Type!! \n";
                break;
        }
    }
}

void MiniECS::Unit::removeModule(ModuleType moduleType)
{
    bool moduleFound = false;
    bool moduleStartFind = false;

    moduleStartFind = true;
    for (auto& module : modules)
    {
        if (module->getType() == moduleType)
        {
            moduleFound = true;
            modules.erase(std::remove(modules.begin(), modules.end(), module), modules.end());
        }
    }

    if (!moduleFound && moduleStartFind)
    {
        std::cout << "Could not find module in: " << name << "\n";
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
