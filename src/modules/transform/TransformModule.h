#ifndef TRANSFORMMODULE_H
#define TRANSFORMMODULE_H

// Imports
#include "../module_base/Module.h"
#include "/opt/homebrew/include/glm/glm.hpp" // Change this to where you have GLM

namespace MiniECS
{
    class TransformModule : public Module{
    public:
        using Module::Module;

        // Transform values
        glm::vec2 position;
        glm::vec2 rotation;
        glm::vec2 scale;

        // Transform start
        void start() override;
    };

}

#endif //TRANSFORMMODULE_H
