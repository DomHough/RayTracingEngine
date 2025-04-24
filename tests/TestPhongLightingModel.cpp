//
// Created by domho on 23/04/2025.
//

#include <gtest/gtest.h>
#include "Lighting/PhongLightingModel.h"
#include "Lighting/AmbientLight.h"
#include "IntersectionPoint.h"
#include "Vec3.h"

TEST(PhongTest, Constructor) {
    PhongLightingModel phongLightingModel(IntersectionPoint(
        Vec3(1.0f, 2.0f, 3.0f),
        Vec3(0.0f, 1.0f, 0.0f),
        RGB(255, 255, 255),
        Material(NormalizedRGB(1,1,1), NormalizedRGB(1,1,1), NormalizedRGB(1,1,1), 0.5f, 1.0f, 0),
        5.0f,
        std::vector<PointLight>(),
        AmbientLight(RGB(255,255,255), 0.5f)
    ));
}