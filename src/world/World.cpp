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

MiniECS::World::World(std::string initName)
{
    worldName = initName;
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

void MiniECS::World::removeUnitByName(std::string unitName)
{
    bool unitFound = false;

    for (auto& unit : worldUnits)
    {
        if (unit->getName() == unitName)
        {
            unitFound = true;
            worldUnits.erase(std::remove(worldUnits.begin(), worldUnits.end(), unit), worldUnits.end());
        }
    }

    if (!unitFound)
    {
        std::cout << "Could not find: " << unitName << "\n";
    }
}

void MiniECS::World::removeUnitByIndex(int index)
{
    worldUnits.erase(std::remove(worldUnits.begin(), worldUnits.end(), worldUnits.at(index)), worldUnits.end());
}

std::unique_ptr<MiniECS::Unit>& MiniECS::World::getUnitByIndex(int index)
{
    return worldUnits.at(index);
}

std::unique_ptr<MiniECS::Unit>& MiniECS::World::getUnitByName(std::string name)
{
    for (std::unique_ptr<Unit>& unit : worldUnits)
    {
        if (unit->getName() == name)
        {
            return unit;
        }
    }
}


const std::vector<std::unique_ptr<MiniECS::Unit>>& MiniECS::World::getUnitsVector() const
{
    return worldUnits;
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
