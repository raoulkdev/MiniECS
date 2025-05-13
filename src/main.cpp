//
// Created by Raoul Kaleba on 4/16/2025.
//

// Imports
#include <memory>
#include "unit/Unit.h"
#include "world/World.h"

// Example use
int main()
{
    // Scene Units
    std::vector<std::unique_ptr<MiniECS::Unit>> units;

    // World
    std::unique_ptr<MiniECS::World> interface = std::make_unique<MiniECS::World>(units);
    interface->introduction();
    interface->displayCommands();

    while (true)
    {
        interface->handleInput();
    }


}
