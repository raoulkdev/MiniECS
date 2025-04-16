//
// Created by Raoul Kaleba on 4/16/2025.
//
#include "TransformModule.h"
#include <iostream>

// Constructor
TransformModule::TransformModule(int startX, int startY, int startZ)
{
    // Set starting X, Y, and Z values
    x = std::move(startX);
    y = std::move(startY);
    z = std::move(startZ);
    std::cout << "Constructed transform, X: " << x << ", Y: " << y << ", Z: " << z << "\n";
}

// Transform update
void TransformModule::update()
{
    // Increment X, Y, and Z values
    x++;
    y++;
    z++;
    std::cout << "Incremented transform, X: " << x << ", Y: " << y << ", Z: " << z << "\n";
}

