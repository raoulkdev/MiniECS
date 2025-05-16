// Imports
#include <iostream>
#include <memory>
#include <algorithm>
#include "World.h"

// Constructor
MiniECS::World::World(std::string initName)
{
    worldName = initName;
}

// Create and add Unit to world
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

// Delete unit by name
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

// Delete Unit by index in world Units vector
void MiniECS::World::removeUnitByIndex(int index)
{
    worldUnits.erase(std::remove(worldUnits.begin(), worldUnits.end(), worldUnits.at(index)), worldUnits.end());
}

// Return Unit by index in world Units vector
std::unique_ptr<MiniECS::Unit>& MiniECS::World::getUnitByIndex(int index)
{
    return worldUnits.at(index);
}

// Return Unit by name
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

// Return world Units vector
const std::vector<std::unique_ptr<MiniECS::Unit>>& MiniECS::World::getUnitsVector() const
{
    return worldUnits;
}

// Start game loop/lifetime at simulated 60 fps
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
