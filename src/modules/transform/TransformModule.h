//
// Created by Raoul Kaleba on 4/16/2025.
//
#ifndef TRANSFORMMODULE_H
#define TRANSFORMMODULE_H

// Imports
#include "../module_base/Module.h"
#include "/opt/homebrew/include/glm/glm.hpp"
namespace MiniECS
{
    // TODO: Add glm & getter & setter functions
    class TransformModule : public Module{
    private:
        // Transform values
        glm::vec2 position;
        glm::vec2 rotation;
        glm::vec2 scale;
    public:
        using Module::Module;

        // Setter functions
        void setPosition(glm::vec2 newPosition);
        void setRotation(glm::vec2 newRotation);
        void setScale(glm::vec2 newScale);

        // Getter functions
        glm::vec2 getPosition();
        glm::vec2 getRotation();
        glm::vec2 getScale();

        // Transform start
        void start() override;
    };

}

#endif //TRANSFORMMODULE_H
