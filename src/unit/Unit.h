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

        // Module functions
        void addModule(ModuleType moduleType);
        void removeModule(ModuleType moduleType);

        template<typename T>
        T* getModule()
        {
            for (auto& module : modules)
            {
                if (auto* result = dynamic_cast<T*>(module.get()))
                {
                    return result;
                }
            }
            std::cerr << "Module of requested type not found in unit: " << name << std::endl;
            return nullptr;
        }

        // Get Name
        std::string getName() const;

        // Get Modules Vector
        std::vector<std::unique_ptr<Module>>& getModulesVector();

        // Call all Module start functions
        void callModuleStart() const;
    };
}


#endif //UNIT_H
