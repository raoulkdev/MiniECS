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
    std::string name;
    std::vector<std::unique_ptr<Module>> modules;
public:
    // Constructor and Destructor
    Unit(std::string newName);
    ~Unit();

    // Add & Remove Modules
    void addModule(std::unique_ptr<Module> module);

    // Call All Module Updates
    void callModuleUpdate();
};

#endif //UNIT_H
