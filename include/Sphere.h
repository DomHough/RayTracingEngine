//
// Created by domho on 18/04/2025.
//

#ifndef SPHERE_H
#define SPHERE_H
#include <optional>

#include "Material.h"
#include "RGB.h"
#include "Rays/OriginRay.h"
#include "Transformation.h"


class Sphere {
public:
    Transformation transformation;
    float radius;
    RGB color;
    Material material;

    Sphere(Transformation transformation, float radius, RGB color, Material material);
    std::optional<float> rayIntersect(OriginRay ray) const;
    std::optional<float> rayIntersect(SegmentRay ray) const;

};



#endif //SPHERE_H
