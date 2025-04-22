//
// Created by domho on 18/04/2025.
//
#include "../include/Scene.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Scene::Scene(Camera camera, Sphere sphere)
    : camera(camera), sphere(sphere) {}

Image Scene::render() const {
    Image image(camera.resolutionX, camera.resolutionY);

    for (int y = 0; y < camera.resolutionY; ++y) {
        for (int x = 0; x < camera.resolutionX; ++x) {
            // Generate ray from camera to pixel
            Ray ray = camera.generateRay(x, y);

            // convert ray to world space
            ray = camera.transformation.objectToWorld(ray);

            // convert ray to object space
            ray = sphere.transformation.worldToObject(ray);


            // Check intersection with sphere
            if (sphere.rayIntersect(ray)) {
                image.setPixel(x, y, sphere.color); // Set pixel color to red if intersected
            } else {
                image.setPixel(x, y, RGB(0,0,0)); // Set pixel color to black if not intersected
            }
        }
    }

    // convert objects to camera space

    return image;
}


