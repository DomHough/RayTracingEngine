//
// Created by domho on 18/04/2025.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "Rays/OriginRay.h"
#include "Transformation.h"


class Camera {
public:
    Transformation transformation;
    unsigned int resolutionX;
    unsigned int resolutionY;
    float hfov;

    Camera(Transformation transformation, unsigned int resolutionX, unsigned int resolutionY, float hfov);

    OriginRay generateRay(int x, int y) const;
};



#endif //CAMERA_H
