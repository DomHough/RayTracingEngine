//
// Created by domho on 22/04/2025.
//

#ifndef AMBIENTLIGHT_H
#define AMBIENTLIGHT_H

#include "RGB.h"


class AmbientLight {
public:
    RGB color;
    float intensity;

    AmbientLight(const RGB& color, float intensity);
};
#endif //AMBIENTLIGHT_H
