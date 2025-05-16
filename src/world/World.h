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
        // Units in the world
        std::vector<std::unique_ptr<Unit>> worldUnits;
        // World name
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

        // Game loop/lifetime functions
        void play() const;
    };

}

#endif //WORLD_H
