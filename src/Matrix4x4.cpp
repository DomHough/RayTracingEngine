//
// Created by domho on 18/04/2025.
//

#include "../include/Matrix4x4.h"
#include "../include/Transformation.h"

#include <cmath>

Matrix4x4::Matrix4x4()
    : matrix{{
        {1.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 1.0f}
    }}
{}

Matrix4x4 Matrix4x4::rotation(Rotation rotation) {
    Matrix4x4 matrix;
    float cosX = std::cos(rotation.x);
    float sinX = std::sin(rotation.x);
    float cosY = std::cos(rotation.y);
    float sinY = std::sin(rotation.y);
    float cosZ = std::cos(rotation.z);
    float sinZ = std::sin(rotation.z);

    matrix.matrix[0][0] = cosY * cosZ;
    matrix.matrix[0][1] = -cosY * sinZ;
    matrix.matrix[0][2] = sinY;
    matrix.matrix[0][3] = 0;

    matrix.matrix[1][0] = sinX * sinY * cosZ + cosX * sinZ;
    matrix.matrix[1][1] = -sinX * sinY * sinZ + cosX * cosZ;
    matrix.matrix[1][2] = -sinX * cosY;
    matrix.matrix[1][3] = 0;

    matrix.matrix[2][0] = -cosX * sinY * cosZ + sinX * sinZ;
    matrix.matrix[2][1] = cosX * sinY * sinZ + sinX * cosZ;
    matrix.matrix[2][2] = cosX * cosY;
    matrix.matrix[2][3] = 0;

    matrix.matrix[3][0] = 0;
    matrix.matrix[3][1] = 0;
    matrix.matrix[3][2] = 0;
    matrix.matrix[3][3] = 1;

    return matrix;
}

Matrix4x4 Matrix4x4::translation(Vec3 translation) {
    Matrix4x4 matrix;
    matrix.matrix[0][3] = translation.x;
    matrix.matrix[1][3] = translation.y;
    matrix.matrix[2][3] = translation.z;
    return matrix;
}

Matrix4x4 Matrix4x4::scale(Vec3 scale) {
    Matrix4x4 matrix;
    matrix.matrix[0][0] = scale.x;
    matrix.matrix[1][1] = scale.y;
    matrix.matrix[2][2] = scale.z;
    return matrix;
}

Matrix4x4 Matrix4x4::transformation(const Transformation& transformation) {
    Matrix4x4 translationMatrix = Matrix4x4::translation(transformation.translation);
    Matrix4x4 rotationMatrix = Matrix4x4::rotation(transformation.rotation);
    Matrix4x4 scaleMatrix = Matrix4x4::scale(transformation.scale);

    return translationMatrix * rotationMatrix * scaleMatrix;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const {
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

Vec3 Matrix4x4::operator*(const Vec3& vec) const {
    float x = matrix[0][0] * vec.x + matrix[0][1] * vec.y + matrix[0][2] * vec.z + matrix[0][3];
    float y = matrix[1][0] * vec.x + matrix[1][1] * vec.y + matrix[1][2] * vec.z + matrix[1][3];
    float z = matrix[2][0] * vec.x + matrix[2][1] * vec.y + matrix[2][2] * vec.z + matrix[2][3];
    return Vec3(x, y, z);
}