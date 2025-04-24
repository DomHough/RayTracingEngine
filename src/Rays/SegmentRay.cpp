//
// Created by domho on 22/04/2025.
//


#include "Rays/SegmentRay.h"

SegmentRay::SegmentRay(const Vec3& origin, const Vec3& end)
    : origin(origin), end(end), direction((end-origin).normalize()) {}

float SegmentRay::length() const {
    return (end - origin).length();
}