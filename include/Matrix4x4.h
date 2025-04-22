//
// Created by domho on 18/04/2025.
//

#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#include <array>

#include "Rotation.h"
#include "Vec3.h"

class Transformation;


class Matrix4x4 {
public:
    std::array<std::array<float, 4>, 4> matrix;

    Matrix4x4();
    static Matrix4x4 rotation(Rotation rotation);
    static Matrix4x4 translation(Vec3 translation);
    static Matrix4x4 scale(Vec3 scale);
    static Matrix4x4 transformation(const Transformation& transformation);

    Matrix4x4 operator*(const Matrix4x4& other) const;
    Vec3 operator*(const Vec3& vec) const;


};
#endif //MATRIX4X4_H
