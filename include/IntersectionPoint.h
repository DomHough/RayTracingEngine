//
// Created by domho on 22/04/2025.
//

#ifndef INTERSECTIONPOINT_H
#define INTERSECTIONPOINT_H

#include "Vec3.h"
#include "RGB.h"
#include "Material.h"
#include "Lighting/PointLight.h"
#include <vector>

#include "Lighting/AmbientLight.h"

class IntersectionPoint {
public:
    Vec3 position;
    Vec3 normal;
    RGB color;
    Material material;
    Vec3 viewDirection;
    std::vector<PointLight> lights;
    AmbientLight ambientLight;

    IntersectionPoint(const Vec3& position, const Vec3& normal, const RGB& color,
                      const Material& material, Vec3 viewDirection,
                      const std::vector<PointLight>& lights, const AmbientLight& ambientLight);
};
#endif //INTERSECTIONPOINT_H
