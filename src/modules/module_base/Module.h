//
// Created by Raoul Kaleba on 4/15/2025.
//
#ifndef MODULE_H
#define MODULE_H

class Module {
public:
    // Constructor and Destructor
    Module();
    virtual ~Module() = default;

    // Update
    virtual void update();
};

#endif //MODULE_H
