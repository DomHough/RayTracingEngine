//
// Created by domho on 18/04/2025.
//

#ifndef IMAGE_H
#define IMAGE_H
#include <vector>

#include "RGB.h"
#include <SFML/Graphics.hpp>


class Image {
public:
    unsigned int width;
    unsigned int height;
    std::vector<std::vector<RGB>> pixels;

    Image(unsigned int width, unsigned int height);
    void setPixel(int x, int y, RGB color);

    sf::Image renderToSFML() const;
};

#endif //IMAGE_H
