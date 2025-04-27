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

Interface::Interface(std::vector<std::unique_ptr<Unit>>& initSceneUnits)
    : sceneUnits(initSceneUnits) {}

void Interface::introduction() const
{
    std::cout << "Welcome to MiniECS by Raoul Kaleba\n";
}

void Interface::displayCommands() const
{
    std::cout << "Your avaliable commands are\n"
    << "create_unit\n"
    << "add_module\n"
    << "remove_module\n"
    << "play\n";
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

    // TODO: Fix cannot find bug after creating or failing to create
    for (auto& unit : sceneUnits)
    {
        if (unit->getName() == unitName)
        {
            found = true;
            switch (moduleType)
            {
            case 1:
                unit->addModule(std::make_unique<RendererModule>("Renderer"));
                break;;
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
        std::cout << "Could not find: " << unitName << "\n";
    }

}

void Interface::removeModule()
{
    bool unitFound = false;
    bool moduleFound = false;
    std::string unitName;
    int moduleID;
    std::cout << "Unit Name: ";
    std::getline(std::cin, unitName);
    std::cout << "Module ID: ";
    std::cin >> moduleID;

    // TODO: Fix cannot find bug after creating or failing to create
    for (auto& unit : sceneUnits)
    {
        if (unit->getName() == unitName)
        {
            unitFound = true;
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
    if (!moduleFound)
    {
        std::cout << "Could not find module in: " << unitName << " with ID: " << moduleID << "\n";
    }

}

void Interface::play()
{
    for (auto& unit : sceneUnits)
    {
        unit->callModuleStart();
    }
}

void Interface::handleInput()
{
    std::string command;
    std::cout << "Enter command: ";
    std::getline(std::cin, command);

    if (command == "create_unit") {
        createUnit();
    } else if (command == "add_module") {
        addModule();
    } else if (command == "remove_module")
    {
        removeModule();
    } else if (command == "play") {
        play();
    } else {
        std::cout << "Unknown command.\n";
    }
}
