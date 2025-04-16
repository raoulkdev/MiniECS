//
// Created by Raoul Kaleba on 4/15/2025.
//
#ifndef UNIT_H
#define UNIT_H

// Imports
#include <iostream>
#include <vector>

#include "../modules/module_base/Module.h"


class Unit {
private:
    std::string name;
    std::unique_ptr<std::vector<Module>> modules;
public:
    // Constructor and Destructor
    Unit(std::string newName, std::unique_ptr<Module>);
    ~Unit();

    // Add & Remove Modules
    void addModule(std::unique_ptr<Module>);
    void removeModule(std::unique_ptr<Module>);
};



#endif //UNIT_H
