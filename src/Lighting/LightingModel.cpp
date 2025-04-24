//
// Created by domho on 22/04/2025.
//


#include "Lighting/PhongLightingModel.h"

LightingModel::LightingModel() = default;

LightingModel::~LightingModel() = default;

RGB LightingModel::computeLighting(const IntersectionPoint& intersectionPoint) {
    return RGB(0, 0, 0);
}

RGB LightingModel::computeAmbient(const IntersectionPoint& intersectionPoint) {
    return RGB(0, 0, 0);
}

RGB LightingModel::computeDiffuse(const IntersectionPoint& intersectionPoint) {
    return RGB(0, 0, 0);
}

RGB LightingModel::computeSpecular(const IntersectionPoint& intersectionPoint) {
    return RGB(0, 0, 0);
}