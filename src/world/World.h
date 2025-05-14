//
// Created by Raoul Kaleba on 4/18/2025.
//
#ifndef WORLD_H
#define WORLD_H

// Imports
#include <vector>
#include <memory>
#include <thread>
#include "../unit/Unit.h"

namespace MiniECS
{
    class World {
    private:
        std::vector<std::unique_ptr<Unit>> worldUnits;
        std::string worldName;
    public:
        // Constructor
        explicit World(std::string initName);

        // Destructor
        ~World() = default;

        // Unit Functions
        void createUnit(std::string newUnitName);
        void removeUnitByName(std::string unitName);
        void removeUnitByIndex(int index);
        std::unique_ptr<Unit>& getUnitByName(std::string name);
        std::unique_ptr<Unit>& getUnitByIndex(int index);
        const std::vector<std::unique_ptr<Unit>>& getUnitsVector() const;

        // Module functions
        void addModule(std::unique_ptr<Unit>& parentUnit, ModuleType moduleType);
        void removeModule(std::unique_ptr<Unit> parentUnit, ModuleType moduleType);

        // Game loop/lifetime functions
        void play() const;
    };

}

#endif //WORLD_H
