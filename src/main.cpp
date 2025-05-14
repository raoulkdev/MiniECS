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
    scene->addModule(scene->getUnitByName("u1"), MiniECS::ModuleType::Renderer);
    scene->addModule(scene->getUnitByName("u1"), MiniECS::ModuleType::Transform);
    scene->removeModule(scene->getUnitByName("u1"), MiniECS::ModuleType::Transform);
    scene->play();

}
