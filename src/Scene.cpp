//
// Created by domho on 18/04/2025.
//
#include "Scene.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "IntersectionPoint.h"
#include "Lighting/PhongLightingModel.h"
#include "Rays/OriginRay.h"

Scene::Scene(Camera camera, std::vector<Sphere> spheres, std::vector<PointLight> lights, AmbientLight ambientLight)
    : camera(camera), spheres(spheres), lights(lights), ambientLight(ambientLight) {}

Image Scene::render() const {
    PhongLightingModel phongLightingModel;
    Image image(camera.resolutionX, camera.resolutionY);

    for (int y = 0; y < camera.resolutionY; ++y) {
        for (int x = 0; x < camera.resolutionX; ++x) {
            // Generate ray from camera to pixel
            OriginRay cameraSpaceRay = camera.generateRay(x, y);

            // convert ray to world space
            OriginRay worldSpaceRay = camera.transformation.objectToWorld(cameraSpaceRay);

            // loop through spheres
            for (const Sphere& sphere : spheres) {
                // convert sphere to world space
                OriginRay sphereSpaceRay = sphere.transformation.worldToObject(worldSpaceRay);

                // Check intersection with sphere
                std::optional<float> intersection = sphere.rayIntersect(sphereSpaceRay);
                if (intersection) {
                    // get a list of lights with direct visual to intersection point
                    std::vector<PointLight> intersectionLights;
                    for (const PointLight& light : lights) {
                        SegmentRay pointLightRay(worldSpaceRay.at(intersection.value()), light.transformation.translation);

                        // Check if light is occluded by spheres
                        bool occluded = false;
                        for (const Sphere& otherSphere : spheres) {
                            SegmentRay sphereSpacePointLightRay = otherSphere.transformation.worldToObject(pointLightRay);
                            std::optional<float> intersetion = otherSphere.rayIntersect(sphereSpacePointLightRay);

                            if (intersetion) {
                                occluded = true;
                                break;
                            }
                        }
                        if (!occluded) {
                            intersectionLights.push_back(light);
                        }
                    }
                    // create intersection point
                    IntersectionPoint intersectionPoint(
                        worldSpaceRay.at(intersection.value()),
                        sphere.transformation.objectToWorld(sphereSpaceRay.at(intersection.value())).normalize(),
                        sphere.color,
                        sphere.material,
                        (worldSpaceRay.at(intersection.value()) - camera.transformation.translation).normalize(),
                        intersectionLights,
                        ambientLight
                        );
                    RGB color = phongLightingModel.computeLighting(intersectionPoint);
                    image.setPixel(x, y, color); // Set pixel color to red if intersected
                }
            }
        }
    }

    // convert objects to camera space

    return image;
}


