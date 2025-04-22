//
// Created by domho on 22/04/2025.
//

#ifndef RAY_H
#define RAY_H

#include "Vec3.h"


class Ray {
public:
    Vec3 origin; // Origin of the ray
    Vec3 direction; // Direction of the ray

    Ray(const Vec3& origin, const Vec3& direction);

    // Function to get a point along the ray at a given distance t
    Vec3 at(float t) const;
};

#endif //RAY_H
