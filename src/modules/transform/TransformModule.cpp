//
// Created by Raoul Kaleba on 4/16/2025.
//
#include "TransformModule.h"
#include <iostream>

void MiniECS::TransformModule::setPosition(glm::vec2 newPosition)
{
    position = newPosition;
}

void MiniECS::TransformModule::setRotation(glm::vec2 newRotation)
{
    rotation = newRotation;
}

void MiniECS::TransformModule::setScale(glm::vec2 newScale)
{
    scale = newScale;
}

glm::vec2 MiniECS::TransformModule::getPosition()
{
    return position;
}

glm::vec2 MiniECS::TransformModule::getRotation()
{
    return rotation;
}

glm::vec2 MiniECS::TransformModule::getScale()
{
    return scale;
}

// Transform start
void MiniECS::TransformModule::start()
{
    std::cout << "Update / Transform -> Position: " <<
        position.x << ", " << position.y <<
            ", Rotation: " << rotation.x << ", " << rotation.y <<
                ", Scale: " << scale.x << ", " << scale.y << "\n";
}

