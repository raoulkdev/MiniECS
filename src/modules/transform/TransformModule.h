//
// Created by Raoul Kaleba on 4/16/2025.
//
#ifndef TRANSFORMMODULE_H
#define TRANSFORMMODULE_H

// Imports
#include "../module_base/Module.h"

class TransformModule : public Module{
private:
    // Transform values
    int x;
    int y;
    int z;
public:
    // Constructor
    TransformModule(int startX, int startY, int startZ);

    // Transform update
    void update() override;
};

#endif //TRANSFORMMODULE_H
