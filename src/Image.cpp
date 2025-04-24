//
// Created by domho on 18/04/2025.
//
#include "Image.h"

Image::Image(const unsigned int width, const unsigned int height) :
    width(width),
    height(height),
    pixels(height, std::vector<RGB>(width)) {};

void Image::setPixel(int x, int y, RGB color) {
    if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
        throw std::out_of_range("Pixel coordinates out of bounds");
    }
    this->pixels[y][x] = color;
}

sf::Image Image::renderToSFML() const {
    sf::Image image({this->width, this->height});
    for (int y = 0; y < this->height; ++y) {
        for (int x = 0; x < this->width; ++x) {
            // Set the pixel color to white
            image.setPixel(sf::Vector2u(x, y), sf::Color(this->pixels[y][x].r, this->pixels[y][x].g, this->pixels[y][x].b));
        }
    }
    return image;
}