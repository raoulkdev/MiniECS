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
    bool unitFound = false;
    for (std::unique_ptr<Unit> unit : worldUnits)
    {
        if (unit->getName() == name)
        {
            unitFound = true;
            return unit;
        }
    }

    if (!unitFound)
    {
        std::cout << "Could not find unit!\n";
    }
}


void MiniECS::World::addModule(std::unique_ptr<Unit> parentUnit, ModuleType moduleType)
{
    bool found;

    for (auto& unit : worldUnits)
    {
        if (unit == parentUnit)
        {
            found = true;
            switch (moduleType)
            {
                case ModuleType::Renderer:
                unit->addModule(std::make_unique<RendererModule>(ModuleType::Renderer));
                break;
                case ModuleType::Transform:
                unit->addModule(std::make_unique<TransformModule>(ModuleType::Transform));
                break;
            default:
                std::cout << "Invalid Module Type!! \n";
                break;
            }
        }
    }
    if (!found)
    {
        std::cout << "Could not find Unit: " << parentUnit->getName() << "\n";
    }

}

void MiniECS::World::removeModuleByID(std::unique_ptr<Unit> parentUnit, int moduleID) const
{
    bool unitFound = false;
    bool moduleFound = false;
    bool moduleStartFind = false;

    for (auto& unit : worldUnits)
    {
        if (unit == parentUnit)
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
        std::cout << "Could not find: " << parentUnit->getName() << "\n";
    }
    if (!moduleFound && moduleStartFind)
    {
        std::cout << "Could not find module in: " << parentUnit->getName() << " with ID: " << moduleID << "\n";
    }
}

void MiniECS::World::removeModuleByIndex(std::unique_ptr<Unit> parentUnit, int index)
{
    auto parModulesVec = parentUnit->getModulesVector();
    parModulesVec.erase(std::remove(parModulesVec.begin(), parModulesVec.end(), parModulesVec.at(index)), parModulesVec.end());
}

std::unique_ptr<MiniECS::Module> & MiniECS::World::getModuleByID(std::unique_ptr<Unit> parentUnit, int moduleID) const
{
    bool unitFound = false;
    bool moduleFound = false;
    bool moduleStartFind = false;

    for (auto& unit : worldUnits)
    {
        if (unit == parentUnit)
        {
            unitFound = true;
            moduleStartFind = true;
            for (auto& module : unit->getModulesVector())
            {
                std::vector<std::unique_ptr<Module>>& modulesVec = unit->getModulesVector();
                if (module->getId() == moduleID)
                {
                    moduleFound = true;
                   return module;
                }
            }
        }
    }

    if (!unitFound)
    {
        std::cout << "Could not find: " << parentUnit->getName() << "\n";
    }
    if (!moduleFound && moduleStartFind)
    {
        std::cout << "Could not find module in: " << parentUnit->getName() << " with ID: " << moduleID << "\n";
    }
}

std::unique_ptr<MiniECS::Module> & MiniECS::World::getModuleByIndex(std::unique_ptr<Unit> parentUnit, int index) const
{
    auto parModulesVec = parentUnit->getModulesVector();
    return parModulesVec.at(index);
}

std::unique_ptr<MiniECS::Module> & MiniECS::World::getModuleByID(std::unique_ptr<Unit> parentUnit, int moduleID)
{
    bool unitFound = false;
    bool moduleFound = false;
    bool moduleStartFind = false;

    for (std::unique_ptr<Unit>& unit : worldUnits)
    {
        if (unit == parentUnit)
        {
            unitFound = true;
            moduleStartFind = true;
            for (auto& module : unit->getModulesVector())
            {
                std::vector<std::unique_ptr<Module>>& modulesVec = unit->getModulesVector();
                if (module->getId() == moduleID)
                {
                    moduleFound = true;
                    return module;
                }
            }
        }
    }

    if (!unitFound)
    {
        std::cout << "Could not find: " << parentUnit->getName() << "\n";
    }
    if (!moduleFound && moduleStartFind)
    {
        std::cout << "Could not find module in: " << parentUnit->getName() << " with ID: " << moduleID << "\n";
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
