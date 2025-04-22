//
// Created by domho on 22/04/2025.
//

#include "../include/Ray.h"


Ray::Ray(const Vec3& origin, const Vec3& direction)
    : origin(origin), direction(direction.normalise()) {}

Vec3 Ray::at(float t) const {
    return origin + direction * t;
}