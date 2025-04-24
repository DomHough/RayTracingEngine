//
// Created by domho on 23/04/2025.
//

#ifndef NORMALIZEDRGB_H
#define NORMALIZEDRGB_H

#include "RGB.h"

class NormalizedRGB {
public:
    float r;
    float g;
    float b;

    NormalizedRGB(float r, float g, float b);

    RGB operator*(const RGB& other) const;
};
#endif //NORMALIZEDRGB_H
