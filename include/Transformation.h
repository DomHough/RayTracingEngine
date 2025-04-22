//
// Created by domho on 21/04/2025.
//

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "Matrix4x4.h"
#include "Ray.h"
#include "Vec3.h"
#include "Rotation.h"


class Transformation {
public:
    Vec3 translation;
    Rotation rotation;
    Vec3 scale;

    Transformation(Vec3 translation=Vec3(), Rotation rotation=Rotation(), Vec3 scale=Vec3());
    Transformation inverse() const;
    // Transformation operator~() const;

    Matrix4x4 getMatrix() const;
    Matrix4x4 getInverseMatrix() const;
    Matrix4x4 getTranslationMatrix() const;
    Matrix4x4 getRotationMatrix() const;

    Ray worldToObject(const Ray& ray) const;
    Ray objectToWorld(const Ray& ray) const;
};
#endif //TRANSFORMATION_H
