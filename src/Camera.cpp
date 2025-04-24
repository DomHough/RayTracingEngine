//
// Created by domho on 18/04/2025.
//

#include "Camera.h"


#include <cmath>

Camera::Camera(Transformation transformation, unsigned int resolutionX, unsigned int resolutionY, float hfov)
    : transformation(transformation), resolutionX(resolutionX), resolutionY(resolutionY), hfov(hfov) {}

OriginRay Camera::generateRay(int x, int y) const {
    float aspectRatio = static_cast<float>(resolutionX) / static_cast<float>(resolutionY);

    float x_ndc = (x + 0.5f) / resolutionX;
    float y_ndc = (y + 0.5f) / resolutionY;
    float x_screen = (2.0f * x_ndc - 1.0f) * aspectRatio * std::tan(hfov / 2.0f);
    float y_screen = (1.0f - 2.0f * y_ndc) * std::tan(hfov / 2.0f);
    Vec3 rayDirection(x_screen, y_screen, -1.0f); // Assuming camera looks down -Z axis
    return OriginRay(Vec3(0,0,0), rayDirection);
}