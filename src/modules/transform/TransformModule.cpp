//
// Created by Raoul Kaleba on 4/16/2025.
//
#include "TransformModule.h"
#include <iostream>

TransformModule::TransformModule(int startX, int startY, int startZ)
{
    x = std::move(startX);
    y = std::move(startY);
    z = std::move(startZ);
    std::cout << "Constructed transform, X: " << x << ", Y: " << y << ", Z: " << z << "\n";
}


void TransformModule::update()
{
    x++;
    y++;
    z++;
    std::cout << "Incremented transform, X: " << x << ", Y: " << y << ", Z: " << z << "\n";
}

