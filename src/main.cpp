//
// Created by Raoul Kaleba on 4/16/2025.
//
#include <iostream>
#include <memory>

// Imports
#include "unit/Unit.h"
#include "modules/module_base/Module.h"


int main()
{
    std::unique_ptr<Unit> unit1 = std::make_unique<Unit>("Unit1");
    unit1->addModule(std::make_unique<Module>());
    unit1->callModuleUpdate();
    return 0;
}
