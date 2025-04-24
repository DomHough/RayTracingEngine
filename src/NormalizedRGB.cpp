//
// Created by domho on 23/04/2025.
//

#include "NormalizedRGB.h"
#include <algorithm>

NormalizedRGB::NormalizedRGB(float r, float g, float b) : r(std::clamp(r, 0.0f, 1.0f)), g(std::clamp(g, 0.0f, 1.0f)), b(std::clamp(b, 0.0f, 1.0f)) {}

RGB NormalizedRGB::operator*(const RGB& other) const {
    return RGB(r * other.r, g * other.g, b * other.b);
}