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

        // CLI functions
        void introduction() const;
        void displayCommands() const;
        void handleInput();

        // Unit Functions
        void createUnit();
        void addModule();
        void removeModule() const;

        // Game loop/lifetime functions
        void play() const;
    };

}

#endif //WORLD_H
