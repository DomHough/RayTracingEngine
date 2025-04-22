//
// Created by domho on 18/04/2025.
//
#include <cmath>

#include "../include/Vec3.h"

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator*(float i) const {
    return Vec3(x * i, y * i, z * i);
}
Vec3 Vec3::operator*(const Vec3& other) const {
    return Vec3(x * other.x, y * other.y, z * other.z);
}
Vec3 operator*(float i, Vec3& v) {
    return Vec3(v.x * i, v.y * i, v.z * i);
}

Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3(-other.x, -other.y, -other.z);
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "Vec3(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

float Vec3::dot(const Vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

float Vec3::squaredLength() const {
    return x*x + y*y + z*z;
}

Vec3 Vec3::normalise() const {
    float length = sqrt(squaredLength());
    if (length == 0) {
        return Vec3(0, 0, 0); // Avoid division by zero
    }
    return Vec3(x / length, y / length, z / length);
}