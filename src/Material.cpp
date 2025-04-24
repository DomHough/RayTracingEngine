//
// Created by domho on 22/04/2025.
//


#include "Material.h"

#include <NormalizedRGB.h>

Material::Material(NormalizedRGB ambientReflectance, NormalizedRGB diffuseReflectance, NormalizedRGB specularReflectance,
                   float shininess, float transparency, float refractiveIndex)
    : ambientReflectance(ambientReflectance), diffuseReflectance(diffuseReflectance),
      specularReflectance(specularReflectance), shininess(shininess),
      transparency(transparency), refractiveIndex(refractiveIndex) {}
