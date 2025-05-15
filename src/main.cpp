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
    scene->getUnitByName("u1")->addModule(MiniECS::ModuleType::Renderer);
    scene->getUnitByName("u1")->addModule(MiniECS::ModuleType::Transform);
    auto& trans = scene->getUnitByName("u1")->getModule(MiniECS::ModuleType::Transform);
    scene->getUnitByName("u1")->addModule(MiniECS::ModuleType::Transform);

    // TOD: Add specific Module manipulation functions
    //trans->
    //scene->play();
}
