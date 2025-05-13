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
        std::vector<std::unique_ptr<MiniECS::Unit>> worldUnits;
    public:
        // Constructor
        explicit World();

        // Destructor
        ~World() = default;

        // Unit Functions
        void createUnit(std::string newUnitName);
        void addModule(std::string unitName, int moduleType);
        void removeModule(std::string unitName, int moduleID) const;

        // Game loop/lifetime functions
        void play() const;
    };

}

#endif //WORLD_H
