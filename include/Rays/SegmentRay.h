//
// Created by domho on 22/04/2025.
//

#ifndef SEGMENTRAY_H
#define SEGMENTRAY_H

#include "../Vec3.h"

class SegmentRay {
public:
    Vec3 origin; // Origin of the ray
    Vec3 end; // End point of the ray
    Vec3 direction; // Direction of the ray

    SegmentRay(const Vec3& origin, const Vec3& end);
    float length() const;
};

#endif //SEGMENTRAY_H
