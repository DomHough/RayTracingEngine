//
// Created by domho on 18/04/2025.
//
#include "../include/Scene.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Scene::Scene(Camera camera, std::vector<Sphere> spheres)
    : camera(camera), spheres(spheres) {}

Image Scene::render() const {
    Image image(camera.resolutionX, camera.resolutionY);

    for (int y = 0; y < camera.resolutionY; ++y) {
        for (int x = 0; x < camera.resolutionX; ++x) {
            // Generate ray from camera to pixel
            Ray cameraSpaceRay = camera.generateRay(x, y);

            // convert ray to world space
            Ray worldSpaceRay = camera.transformation.objectToWorld(cameraSpaceRay);

            // loop through spheres
            for (const Sphere& sphere : spheres) {
                // convert sphere to world space
                Ray sphereSpaceray = sphere.transformation.worldToObject(worldSpaceRay);

                // Check intersection with sphere
                if (sphere.rayIntersect(sphereSpaceray)) {
                    image.setPixel(x, y, sphere.color); // Set pixel color to red if intersected
                }
            }
        }
    }

    // convert objects to camera space

    return image;
}


