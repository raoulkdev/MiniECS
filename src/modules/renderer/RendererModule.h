//
// Created by Raoul Kaleba on 4/16/2025.
//
#ifndef RENDERERMODULE_H
#define RENDERERMODULE_H

// Imports
#include "../module_base/Module.h"

class RendererModule : public Module{
public:
    // Constructor
    RendererModule();

    // Renderer update
    void update() override;

};

#endif //RENDERERMODULE_H
