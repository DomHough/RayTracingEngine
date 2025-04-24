//
// Created by domho on 18/04/2025.
//
#include "RGB.h"
#include "NormalizedRGB.h"

#include <algorithm>
#include <ostream>

RGB::RGB(int r, int g, int b)
    : r(static_cast<unsigned char>(std::clamp(r, 0, 255))),
      g(static_cast<unsigned char>(std::clamp(g, 0, 255))),
      b(static_cast<unsigned char>(std::clamp(b, 0, 255))) {}

RGB RGB::operator*(float scalar) const {
    return RGB(r*scalar, g*scalar, b*scalar);
}

RGB operator*(float scalar, const RGB &color) {
    return color * scalar;
}
RGB RGB::operator*(const NormalizedRGB &other) const {
    return RGB(static_cast<int>(r * other.r), static_cast<int>(g * other.g), static_cast<int>(b * other.b));
}

RGB RGB::operator+(const RGB &other) const {
    return RGB(r+other.r, g+other.g, b+other.b);
}

RGB RGB::operator+=(const RGB &other) {
    r = std::clamp(r + other.r, 0, 255);
    g = std::clamp(g + other.g, 0, 255);
    b = std::clamp(b + other.b, 0, 255);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const RGB& color) {
    os << "RGB(" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ")";
    return os;
}