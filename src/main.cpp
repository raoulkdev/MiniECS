// Imports
#include <memory>
#include "modules/transform/TransformModule.h"
#include "unit/Unit.h"
#include "world/World.h"

// Example use
int main()
{
    // Create World
    MiniECS::World scene("Scene");

    // Create new unit inside the world
    scene.createUnit("u1");

    // Add a renderer module to the new unit
    scene.getUnitByName("u1")->addModule(MiniECS::ModuleType::Renderer);

    // Add a transform module to the new unit
    scene.getUnitByName("u1")->addModule(MiniECS::ModuleType::Transform);

    // Set transform position
    scene.getUnitByName("u1")->getModule<MiniECS::TransformModule>()->position = {22.5f, 33.4f};

    // Play the scene
    scene.play();
}
