//
// Created by Raoul Kaleba on 4/18/2025.
//
#ifndef INTERFACE_H
#define INTERFACE_H

// Imports
#include <vector>
#include <memory>
#include "../unit/Unit.h"

namespace MiniECSInterface
{
    class Interface {
    private:
        std::vector<std::unique_ptr<MiniECS::Unit>>& sceneUnits;
    public:
        // Constructor
        explicit Interface(std::vector<std::unique_ptr<MiniECS::Unit>>& initSceneUnits);

        // Destructor
        ~Interface() = default;

        // Interface functions
        void introduction() const;
        void displayCommands() const;

        // Unit Functions
        void createUnit();
        void addModule();
        void removeModule() const;
        void play() const;

        void handleInput();
    };

}

#endif //INTERFACE_H
