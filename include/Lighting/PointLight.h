//
// Created by domho on 22/04/2025.
//

#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Transformation.h"
#include "RGB.h"

class PointLight {
public:
    Transformation transformation;
    RGB color;
    float intensity;

    PointLight(Transformation transformation=Transformation(), RGB color=RGB(), float intensity=1.0f);
};
#endif //POINTLIGHT_H
