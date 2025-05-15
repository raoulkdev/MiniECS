//
// Created by Raoul Kaleba on 4/16/2025.
//

// Imports
#include <memory>

#include "modules/transform/TransformModule.h"
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
    // TODO: Fix only accessable as ModuleBase

    scene->getUnitByName("u1")->getModuleAs<MiniECS::TransformModule>()->setPosition({1, 22});

    scene->play();
}
