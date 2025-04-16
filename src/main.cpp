//
// Created by Raoul Kaleba on 4/16/2025.
//
#include <iostream>
#include <memory>

// Imports
#include "unit/Unit.h"
#include "modules/renderer/RendererModule.h"
#include "modules/transform/TransformModule.h"


int main()
{
    std::unique_ptr<Unit> unit1 = std::make_unique<Unit>("Unit1");
    unit1->addModule(std::make_unique<RendererModule>());
    unit1->addModule(std::make_unique<TransformModule>(23, 43, 52));
    unit1->callModuleUpdate();
    return 0;
}
