//
// Created by domho on 18/04/2025.
//

#ifndef VEC3_H
#define VEC3_H
#include <ostream>


class Vec3 {
public:
    float x;
    float y;
    float z;

    Vec3(float x = 0, float y = 0, float z = 0);
    Vec3 operator+(const Vec3& other) const;

    Vec3 operator*(float i) const;
    Vec3 operator*(const Vec3& other) const;
    friend Vec3 operator*(float i, Vec3& v);

    Vec3 operator-(const Vec3& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Vec3& v);

    float dot(const Vec3& other) const;
    float squaredLength() const;

    Vec3 normalise() const;



};
#endif //VEC3_H
