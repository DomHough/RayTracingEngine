//
// Created by domho on 18/04/2025.
//

#ifndef SCENE_H
#define SCENE_H
#include "Camera.h"
#include "Image.h"
#include "Sphere.h"
#include "Lighting/PointLight.h"
#include <SFML/Graphics.hpp>

#include "Lighting/AmbientLight.h"


class Scene {
public:
    Camera camera;
    std::vector<Sphere> spheres;
    std::vector<PointLight> lights;
    AmbientLight ambientLight;
    Scene(Camera camera, std::vector<Sphere> spheres, std::vector<PointLight> lights, AmbientLight ambientLight);

    Image render() const;


};



#endif //SCENE_H
