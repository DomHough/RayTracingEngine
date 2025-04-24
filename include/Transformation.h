//
// Created by domho on 21/04/2025.
//

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "Matrix4x4.h"
#include "Rays/OriginRay.h"
#include "Vec3.h"
#include "Rotation.h"
#include "Rays/SegmentRay.h"


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

    OriginRay worldToObject(const OriginRay& ray) const;
    SegmentRay worldToObject(const SegmentRay& ray) const;

    OriginRay objectToWorld(const OriginRay& ray) const;
    SegmentRay objectToWorld(const SegmentRay& ray) const;
    Vec3 objectToWorld(const Vec3& point) const;
};
#endif //TRANSFORMATION_H
