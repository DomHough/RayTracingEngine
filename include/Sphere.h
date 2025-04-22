//
// Created by domho on 18/04/2025.
//

#ifndef SPHERE_H
#define SPHERE_H
#include <optional>

#include "RGB.h"
#include "Ray.h"
#include "Transformation.h"


class Sphere {
public:
    Transformation transformation;
    float radius;
    RGB color;

    Sphere(Transformation transformation, float radius, RGB color);
    std::optional<float> rayIntersect(const Ray ray) const;

};



#endif //SPHERE_H
