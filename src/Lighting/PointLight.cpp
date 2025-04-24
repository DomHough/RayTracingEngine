//
// Created by domho on 22/04/2025.
//

#include "Lighting/PointLight.h"

PointLight::PointLight(Transformation transformation, RGB color, float intensity)
    : transformation(transformation), color(color), intensity(intensity) {}