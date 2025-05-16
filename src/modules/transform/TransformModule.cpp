// Imports
#include "TransformModule.h"
#include <iostream>

// Transform start
void MiniECS::TransformModule::start()
{
    std::cout << "Update / Transform -> Position: " <<
        position.x << ", " << position.y <<
            ", Rotation: " << rotation.x << ", " << rotation.y <<
                ", Scale: " << scale.x << ", " << scale.y << "\n";
}

