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

namespace MiniECS
{
    class Unit {
    private:
        // Unit name
        std::string name;
        // Unit Modules
        std::vector<std::unique_ptr<Module>> modules;
    public:
        // Constructor
        explicit Unit(std::string newName);

        // Destructor
        ~Unit();

        // Add Module
        void addModule(std::unique_ptr<Module> moduleToAdd);

        // Get Name
        std::string getName() const;

        // Get Modules Vector
        std::vector<std::unique_ptr<Module>>& getModulesVector();

        // Call all Module start functions
        void callModuleStart() const;
    };
}


#endif //UNIT_H
