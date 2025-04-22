//
// Created by domho on 18/04/2025.
//

#ifndef SCENE_H
#define SCENE_H
#include "Camera.h"
#include "Image.h"
#include "Sphere.h"
#include <SFML/Graphics.hpp>


class Scene {
public:
    Scene(Camera camera, Sphere sphere);
    Camera camera;
    Sphere sphere;
    Image render() const;


};



#endif //SCENE_H
