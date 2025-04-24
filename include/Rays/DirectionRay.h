//
// Created by domho on 22/04/2025.
//

#ifndef DIRECTIONRAY_H
#define DIRECTIONRAY_H

#include "../Vec3.h"


class DirectionRay {
public:
    Vec3 direction; // Direction of the ray

    DirectionRay(const Vec3& direction);
};

#endif //DIRECTIONRAY_H
