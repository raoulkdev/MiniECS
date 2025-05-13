//
// Created by Raoul Kaleba on 4/18/2025.
//
#include "World.h"

// Imports
#include <iostream>
#include <memory>
#include <algorithm>
#include "../modules/renderer/RendererModule.h"
#include "../modules/transform/TransformModule.h"

MiniECS::World::World()
{
    std::cout << "Created world\n";
}

void MiniECS::World::createUnit(std::string newUnitName)
{
    if (!newUnitName.empty())
    {
        std::unique_ptr<Unit> newUnit = std::make_unique<Unit>(newUnitName);
        worldUnits.push_back(std::move(newUnit));
    }
    else
    {
        std::cout << "New unit name invalid!\n";
    }
}

// TODO: Use an ENUM for module type lookup
void MiniECS::World::addModule(std::string unitName, int moduleType)
{
    bool found;

    for (auto& unit : worldUnits)
    {
        if (unit->getName() == unitName)
        {
            found = true;
            switch (moduleType)
            {
            case 1:
                unit->addModule(std::make_unique<RendererModule>("Renderer"));
                break;
            case 2:
                unit->addModule(std::make_unique<TransformModule>("Transform"));
                break;
            default:
                std::cout << "Invalid Module Type!! \n";
                break;
            }
        }
    }
    if (!found)
    {
        std::cout << "Could not find Unit: " << unitName << "\n";
    }

}

void MiniECS::World::removeModule(std::string unitName, int moduleID) const
{
    bool unitFound = false;
    bool moduleFound = false;
    bool moduleStartFind = false;

    for (auto& unit : worldUnits)
    {
        if (unit->getName() == unitName)
        {
            unitFound = true;
            moduleStartFind = true;
            for (auto& module : unit->getModulesVector())
            {
                std::vector<std::unique_ptr<Module>>& modulesVec = unit->getModulesVector();
                if (module->getId() == moduleID)
                {
                    moduleFound = true;
                    modulesVec.erase(std::remove(modulesVec.begin(), modulesVec.end(), module), modulesVec.end());
                }
            }
        }
    }

    if (!unitFound)
    {
        std::cout << "Could not find: " << unitName << "\n";
    }
    if (!moduleFound && moduleStartFind)
    {
        std::cout << "Could not find module in: " << unitName << " with ID: " << moduleID << "\n";
    }
}


void MiniECS::World::play() const
{
    if (!worldUnits.empty())
    {
        for (auto& unit : worldUnits)
        {
            if (!unit->getModulesVector().empty())
            {
                while (true)
                {
                    unit->callModuleStart();
                    std::this_thread::sleep_for(std::chrono::milliseconds(16));
                }
            }
            else
            {
                std::cout << "No units in the scene have modules\n";
            }
        }
    }
    else
    {
        std::cout << "No units in the scene\n";
    }
}
