//
// Created by domho on 22/04/2025.
//

#ifndef LIGHTINGMODEL_H
#define LIGHTINGMODEL_H

#include "RGB.h"
#include "IntersectionPoint.h"


class LightingModel {
public:
    LightingModel();
    virtual ~LightingModel();

    virtual RGB computeLighting(const IntersectionPoint& intersectionPoint);
    virtual RGB computeAmbient(const IntersectionPoint& intersectionPoint);
    virtual RGB computeDiffuse(const IntersectionPoint& intersectionPoint);
    virtual RGB computeSpecular(const IntersectionPoint& intersectionPoint);
};
#endif //LIGHTINGMODEL_H
