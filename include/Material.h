//
// Created by domho on 22/04/2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H
#include <NormalizedRGB.h>


class Material {
public:
    NormalizedRGB ambientReflectance;
    NormalizedRGB diffuseReflectance;
    NormalizedRGB specularReflectance;
    float shininess;
    float transparency;
    float refractiveIndex;
    Material(NormalizedRGB ambientReflectance, NormalizedRGB diffuseReflectance, NormalizedRGB specularReflectance,
             float shininess, float transparency, float refractiveIndex);
};

#endif //MATERIAL_H
