//
// Created by domho on 22/04/2025.
//

#include "IntersectionPoint.h"

IntersectionPoint::IntersectionPoint(const Vec3& position, const Vec3& normal, const RGB& color,
                                     const Material& material, Vec3 viewDirection,
                                     const std::vector<PointLight>& lights, const AmbientLight& ambientLight)
    : position(position), normal(normal), color(color), material(material),
      viewDirection(viewDirection), lights(lights), ambientLight(ambientLight) {}