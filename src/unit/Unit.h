//
// Created by Raoul Kaleba on 4/15/2025.
//
#ifndef UNIT_H
#define UNIT_H

// Imports
#include <iostream>
#include <vector>
#include <memory>
#include "../modules/module_base/Module.h"

class Unit {
private:
    // Unit name
    std::string name;
    // Unit Modules
    std::vector<std::unique_ptr<Module>> modules;
public:
    // Constructor
    Unit(std::string newName);

    // Destructor
    ~Unit();

    // Add Module
    void addModule(std::unique_ptr<Module> module);

    // Call all Module update functions
    void callModuleUpdate();
};

#endif //UNIT_H
