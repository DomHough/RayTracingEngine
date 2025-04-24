//
// Created by domho on 22/04/2025.
//

#ifndef PHONGLIGHTINGMODEL_H
#define PHONGLIGHTINGMODEL_H

#include "LightingModel.h"

class PhongLightingModel : public LightingModel {
public:
    PhongLightingModel();
    RGB computeLighting(const IntersectionPoint& intersectionPoint) override;
    RGB computeAmbient(const IntersectionPoint& intersectionPoint) override;
    RGB computeDiffuse(const IntersectionPoint& intersectionPoint) override;
    RGB computeSpecular(const IntersectionPoint& intersectionPoint) override;
};
#endif //PHONGLIGHTINGMODEL_H
