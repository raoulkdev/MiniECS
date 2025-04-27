//
// Created by Raoul Kaleba on 4/16/2025.
//
#ifndef TRANSFORMMODULE_H
#define TRANSFORMMODULE_H

// Imports
#include "../module_base/Module.h"
namespace MiniECS
{
    class TransformModule : public Module{
    private:
        // Transform values
        int x = 0;
        int y = 0;
        int z = 0;
    public:
        using Module::Module;

        // Transform start
        void start() override;
    };

}

#endif //TRANSFORMMODULE_H
