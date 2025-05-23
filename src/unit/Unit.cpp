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

// Remove Module
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

// Return Unit name
std::string MiniECS::Unit::getName() const
{
    return name;
}

// Return the Modules vector
std::vector<std::unique_ptr<MiniECS::Module>>& MiniECS::Unit::getModulesVector()
{
    return modules;
}

// Start game loop/lifetime
void MiniECS::Unit::callModuleStart() const
{
    for (const std::unique_ptr<Module> &sModule : modules)
    {
        sModule->start();
    }
}
