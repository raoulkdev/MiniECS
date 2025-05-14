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
    // World
    std::unique_ptr<MiniECS::World> scene = std::make_unique<MiniECS::World>("Scene");
    scene->createUnit("u1");
    scene->addModule("u1", MiniECS::ModuleType::Transform);
    std::cout << scene->getUnitsVector().at(0)->getModulesVector().at(0)->getId();
}
