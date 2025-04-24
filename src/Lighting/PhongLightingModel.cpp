//
// Created by domho on 22/04/2025.
//
#include "Lighting/PhongLightingModel.h"

#include <cmath>


PhongLightingModel::PhongLightingModel() = default;

RGB PhongLightingModel::computeLighting(const IntersectionPoint& intersectionPoint) {
    RGB ambient = computeAmbient(intersectionPoint);
    RGB diffuse = computeDiffuse(intersectionPoint);
    RGB specular = computeSpecular(intersectionPoint);

    return ambient + diffuse + specular;
}

RGB PhongLightingModel::computeAmbient(const IntersectionPoint& intersectionPoint) {
    // Ambient lighting calculation
    return intersectionPoint.material.ambientReflectance * (intersectionPoint.ambientLight.color * intersectionPoint.ambientLight.intensity);
}
//
RGB PhongLightingModel::computeDiffuse(const IntersectionPoint& intersectionPoint) {
    RGB diffuse(0, 0, 0);
    for (const PointLight& light : intersectionPoint.lights) {
        Vec3 lightDirection = (light.transformation.translation - intersectionPoint.position).normalize();
        diffuse += intersectionPoint.material.diffuseReflectance * (light.color * light.intensity) * std::pow(std::max(0.0f, intersectionPoint.normal.dot(lightDirection)), intersectionPoint.material.shininess);
    }
    return diffuse;
}

RGB PhongLightingModel::computeSpecular(const IntersectionPoint& intersectionPoint) {
    RGB specular(0, 0, 0);
    for (const PointLight& light : intersectionPoint.lights) {
        Vec3 lightDirection = (light.transformation.translation - intersectionPoint.position).normalize();
        Vec3 reflectionVector = 2 * intersectionPoint.normal.dot(lightDirection) * intersectionPoint.normal - lightDirection;
        specular += intersectionPoint.material.specularReflectance * (light.color * light.intensity) * std::max(0.0f, reflectionVector.dot(intersectionPoint.viewDirection));
    }
    return specular;
}
