#ifndef RENDERERMODULE_H
#define RENDERERMODULE_H

// Imports
#include "../module_base/Module.h"
#include <iostream>

namespace MiniECS
{
    class RendererModule : public Module{
    public:
        using Module::Module;

        // Renderer start
        void start() override;
    };
}

#endif //RENDERERMODULE_H
