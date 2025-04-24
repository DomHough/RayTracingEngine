//
// Created by domho on 18/04/2025.
//

#ifndef RGB_H
#define RGB_H
#include <ostream>

class NormalizedRGB;

class RGB {
public:
    RGB(int r = 0, int g = 0, int b = 0);

    unsigned char r;
    unsigned char g;
    unsigned char b;

    RGB operator*(float scalar) const;
    friend RGB operator*(float scalar, const RGB &color);
    RGB operator*(const NormalizedRGB &other) const;
    RGB operator+(const RGB& other) const;
    RGB operator+=(const RGB& other);

    friend std::ostream& operator<<(std::ostream& os, const RGB& color);

};
#endif //RGB_H
