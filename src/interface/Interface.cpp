//
// Created by Raoul Kaleba on 4/18/2025.
//
#include "Interface.h"

// Imports
#include <iostream>
#include <memory>
#include <algorithm>
#include "../modules/renderer/RendererModule.h"
#include "../modules/transform/TransformModule.h"
#include <limits>

Interface::Interface(std::vector<std::unique_ptr<Unit>>& initSceneUnits)
    : sceneUnits(initSceneUnits) {}

void Interface::introduction() const
{
    std::cout << "Welcome to MiniECS v0.11 by Raoul Kaleba\n";
}

void Interface::displayCommands() const
{
    std::cout << "Your available commands are:\n"
    << " create_unit -> Create a new Unit with a name\n"
    << " add_module -> Add a Module to a specific Unit by name\n"
    << " remove_module -> Remove a Module from a specific Unit by name\n"
    << " play -> Run all Units' modules' start functions\n"
    << " exit -> Exit MiniECS\n";
}

void Interface::createUnit()
{
    std::string newUnitName;
    std::cout << "New Unit Name: ";
    std::getline(std::cin, newUnitName);
    std::unique_ptr<Unit> newUnit = std::make_unique<Unit>(newUnitName);
    sceneUnits.push_back(std::move(newUnit));
}

void Interface::addModule()
{
    bool found;
    std::string unitName;
    int moduleType;
    std::cout << "Unit Name: ";
    std::getline(std::cin, unitName);
    std::cout << "Module Type (1. Renderer, 2. Transform): ";
    std::cin >> moduleType;

    for (auto& unit : sceneUnits)
    {
        if (unit->getName() == unitName)
        {
            found = true;
            switch (moduleType)
            {
            case 1:
                unit->addModule(std::make_unique<RendererModule>("Renderer"));
                std::cin.ignore();
                break;;
            case 2:
                unit->addModule(std::make_unique<TransformModule>("Transform"));
                std::cin.ignore();
                break;
            default:
                std::cout << "Invalid Module Type!! \n";
                std::cin.ignore();
                break;
            }
        }
    }
    if (!found)
    {
        std::cout << "Could not find Unit: " << unitName << "\n";
        std::cin.ignore();
    }

}

void Interface::removeModule()
{
    bool unitFound = false;
    bool moduleFound = false;
    bool moduleStartFind = false;
    std::string unitName;
    int moduleID;
    std::cout << "Unit Name: ";
    std::getline(std::cin, unitName);

    for (auto& unit : sceneUnits)
    {
        if (unit->getName() == unitName)
        {
            unitFound = true;
            std::cout << "Module ID: ";
            std::cin >> moduleID;
            std::cin.ignore();
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

void Interface::play()
{
    if (!sceneUnits.empty())
    {
        for (auto& unit : sceneUnits)
        {
            if (!unit->getModulesVector().empty())
            {
                unit->callModuleStart();
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

void Interface::handleInput()
{
    std::string command;
    std::cout << "MiniECS/v0.11> ";
    std::getline(std::cin, command);

    if (command == "create_unit") {
        createUnit();
    }
    else if (command == "add_module") {
        addModule();
    }
    else if (command == "remove_module")
    {
        removeModule();
    }
    else if (command == "play") {
        play();
    }
    else if (command == "exit") {
        std::cout << "Exiting MiniECS v0.11\n";
        return exit(0);
    }
    else {
        std::cout << "Unknown command\n";
        displayCommands();
    }
}
