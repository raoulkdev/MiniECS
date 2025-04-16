//
// Created by Raoul Kaleba on 4/15/2025.
//
#ifndef MODULE_H
#define MODULE_H

// Imports
#include <memory>

#include "../../unit/Unit.h"

class Module {
    Unit* owner;
public:
    // Constructor and Destructor
    Module(Unit &newOwner);
    ~Module();

    // Update
    void update();

};



#endif //MODULE_H
