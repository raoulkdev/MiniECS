//
// Created by Raoul Kaleba on 4/16/2025.
//

// Imports
#include <memory>
#include "unit/Unit.h"
#include "interface/Interface.h"

// Example use
int main()
{
    // Scene Units
    std::vector<std::unique_ptr<MiniECS::Unit>> units;

    // Interface
    std::unique_ptr<MiniECSInterface::Interface> interface = std::make_unique<MiniECSInterface::Interface>(units);
    interface->introduction();
    interface->displayCommands();

    while (true)
    {
        interface->handleInput();
    }


}
