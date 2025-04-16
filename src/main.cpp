//
// Created by Raoul Kaleba on 4/16/2025.
//

// Imports
#include <memory>
#include "unit/Unit.h"
#include "modules/renderer/RendererModule.h"
#include "modules/transform/TransformModule.h"

// Example use
int main()
{
    // Make new Unit (Like GameObject from unity)
    std::unique_ptr<Unit> unit1 = std::make_unique<Unit>("Unit1");

    // Add Modules (Like Components from Unity)
    unit1->addModule(std::make_unique<RendererModule>());
    unit1->addModule(std::make_unique<TransformModule>(23, 43, 52));

    // Call all module update functions
    unit1->callModuleUpdate();

    // Finish Program
    return 0;
}
