//
// Created by Raoul Kaleba on 4/15/2025.
//
#ifndef MODULE_H
#define MODULE_H

class Module {
public:
    // Destructor for all derived classes
    virtual ~Module() = default;

    // Default module update
    virtual void update();
};

#endif //MODULE_H
