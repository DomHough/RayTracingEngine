//
// Created by domho on 21/04/2025.
//

#include "../include/Transformation.h"

Transformation::Transformation(Vec3 translation, Rotation rotation, Vec3 scale)
    : translation(translation), rotation(rotation), scale(scale) {}

Transformation Transformation::inverse() const {

    // Inverse of translation
    Vec3 invTranslation = Vec3(-translation.x, -translation.y, -translation.z);

    // Inverse of rotation (assuming rotation is in radians)
    Rotation invRotation = Rotation(-rotation.x, -rotation.y, -rotation.z);

    // Inverse of scale
    Vec3 invScale = Vec3(1.0f / scale.x, 1.0f / scale.y, 1.0f / scale.z);

    return Transformation(invTranslation, invRotation, invScale);
}

Matrix4x4 Transformation::getMatrix() const {
    return Matrix4x4::transformation(*this);
}

Matrix4x4 Transformation::getInverseMatrix() const {
    return Matrix4x4::transformation(inverse());
}

Matrix4x4 Transformation::getTranslationMatrix() const {
    return Matrix4x4::translation(translation);
}

Matrix4x4 Transformation::getRotationMatrix() const {
    return Matrix4x4::rotation(rotation);
}

Ray Transformation::worldToObject(const Ray& ray) const {
    Vec3 origin = inverse().getTranslationMatrix() * ray.origin;
    Vec3 direction = inverse().getRotationMatrix() * ray.direction;
    return Ray(origin, direction);
}

Ray Transformation::objectToWorld(const Ray& ray) const {
    Vec3 origin = getTranslationMatrix() * ray.origin;
    Vec3 direction = getRotationMatrix() * ray.direction;
    return Ray(origin, direction);
}