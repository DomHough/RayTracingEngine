//
// Created by domho on 23/04/2025.
//

#include <gtest/gtest.h>

#include "RGB.h"

TEST(RGBTest, Constructor) {
    RGB color(100, 150, 200);
    EXPECT_EQ(color.r, 100);
    EXPECT_EQ(color.g, 150);
    EXPECT_EQ(color.b, 200);
}

TEST(RGBTest, Clamping) {
    RGB color(300, -50, 256);
    EXPECT_EQ(color.r, 255);
    EXPECT_EQ(color.g, 0);
    EXPECT_EQ(color.b, 255);
}

TEST(RGBTest, Multiplication) {
    RGB color(100, 150, 200);
    RGB result = color * 0.5f;
    EXPECT_EQ(result.r, 50);
    EXPECT_EQ(result.g, 75);
    EXPECT_EQ(result.b, 100);
}