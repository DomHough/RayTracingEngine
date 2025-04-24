//
// Created by domho on 22/04/2025.
//

#include <gtest/gtest.h>
#include "Vec3.h"

TEST(Vec3Test, DefaultConstructor) {
    Vec3 vec;
    EXPECT_FLOAT_EQ(vec.x, 0.0f);
    EXPECT_FLOAT_EQ(vec.y, 0.0f);
    EXPECT_FLOAT_EQ(vec.z, 0.0f);
}

TEST(Vec3Test, ParameterizedConstructor) {
    Vec3 vec(1.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(vec.x, 1.0f);
    EXPECT_FLOAT_EQ(vec.y, 2.0f);
    EXPECT_FLOAT_EQ(vec.z, 3.0f);
}

TEST(Vec3Test, ADD) {
    Vec3 vec1(1.0f, 2.0f, 3.0f);
    Vec3 vec2(4.0f, 5.0f, 6.0f);
    Vec3 result = vec1 + vec2;
    EXPECT_FLOAT_EQ(result.x, 5.0f);
    EXPECT_FLOAT_EQ(result.y, 7.0f);
    EXPECT_FLOAT_EQ(result.z, 9.0f);
}

TEST(Vec3Test, SUB) {
    Vec3 vec1(4.0f, 5.0f, 6.0f);
    Vec3 vec2(1.0f, 2.0f, 3.0f);
    Vec3 result = vec1 - vec2;
    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 3.0f);
    EXPECT_FLOAT_EQ(result.z, 3.0f);
}

TEST(Vec3Test, MULTIPLY) {
    Vec3 vec(1.0f, 2.0f, 3.0f);
    float scalar = 2.0f;
    Vec3 result = vec * scalar;
    EXPECT_FLOAT_EQ(result.x, 2.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
    EXPECT_FLOAT_EQ(result.z, 6.0f);
}

TEST(Vec3Test, DOT) {
    Vec3 vec1(1.0f, 2.0f, 3.0f);
    Vec3 vec2(4.0f, 5.0f, 6.0f);
    float result = vec1.dot(vec2);
    EXPECT_FLOAT_EQ(result, 32.0f);
}

TEST(Vec3Test, LENGTH) {
    Vec3 vec(3.0f, 4.0f, 2.0f);
    float result = vec.length();
    EXPECT_FLOAT_EQ(result, 5.3851647f);
}

TEST(Vec3Test, NORMALIZE) {
    Vec3 vec(3.0f, 4.0f, 2.0f);
    Vec3 result = vec.normalize();
    EXPECT_FLOAT_EQ(result.x, 0.55708601f);
    EXPECT_FLOAT_EQ(result.y, 0.74278134f);
    EXPECT_FLOAT_EQ(result.z, 0.37139067f);
}