//
// Created by domho on 18/04/2025.
//

#include "Sphere.h"

#include <cmath>
#include <iostream>
#include <optional>

Sphere::Sphere(Transformation(transformation), float radius, RGB color, Material material)
    : transformation(transformation), radius(radius), color(color), material(material) {}

// Assume the ray is in object space
std::optional<float> Sphere::rayIntersect(const OriginRay ray) const {
    float a = 1.0f;
    float b = 2.0f * ray.origin.dot(ray.direction);
    float c = ray.origin.squaredLength()- radius * radius;

    float discriminant = b * b - 4.0f * a * c;

    // No intersection
    if (discriminant < 0) {
        return std::nullopt;
    }
    // Intersection
    else {
        float sqrt_discriminant = std::sqrt(discriminant);
        float t1 = (-b - sqrt_discriminant) / (2 * a);
        float t2 = (-b + sqrt_discriminant) / (2 * a);
        if (t1 >= 0) return t1;
        if (t2 >= 0) return t2;
        return std::nullopt; // Both behind the ray
    }

    return 0.0f;
}

std::optional<float> Sphere::rayIntersect(const SegmentRay ray) const {
    float a = 1.0f;
    float b = 2.0f * ray.origin.dot(ray.direction);
    float c = ray.origin.squaredLength()- radius * radius;

    float discriminant = b * b - 4.0f * a * c;

    // No intersection
    if (discriminant < 0) {
        return std::nullopt;
    }
    else {
        float sqrt_discriminant = std::sqrt(discriminant);
        float t1 = (-b - sqrt_discriminant) / (2 * a);
        float t2 = (-b + sqrt_discriminant) / (2 * a);
        if (t1 >= 1e-2f && t1 <= ray.length()-1e-2f) return t1;
        if (t2 >= 1e-2f && t2 <= ray.length()-1e-2f) return t2;
        return std::nullopt; // Both behind the ray
    }
}