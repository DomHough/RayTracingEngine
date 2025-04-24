//
// Created by domho on 22/04/2025.
//

#include "Rays/OriginRay.h"
#include "Vec3.h"


OriginRay::OriginRay(const Vec3& origin, const Vec3& direction)
    : origin(origin), direction(direction.normalize()) {}

Vec3 OriginRay::at(float t) const {
    return origin + direction * t;
}