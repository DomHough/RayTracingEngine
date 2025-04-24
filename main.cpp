#include <iostream>

#include "include/Camera.h"
#include "include/Scene.h"
#include "include/Lighting/PointLight.h"
#include <SFML/Graphics.hpp>


int main() {
    Transformation camera_transformation(Vec3(0, 0, 0), Rotation(0, 0, 0), Vec3(1, 1, 1));
    Camera my_cam(camera_transformation, 1024, 1024, 90);

    Transformation sphere_1_transformation(Vec3(10,0,-50), Rotation(0, 0, 0), Vec3(1, 1, 1));
    Transformation sphere_2_transformation(Vec3(-10,0,-50), Rotation(0, 0, 0), Vec3(1, 1, 1));

    Sphere sphere1(sphere_1_transformation, 10, RGB(255, 0, 0), Material(NormalizedRGB(1,0,0),NormalizedRGB(1,0,0),NormalizedRGB(1,1,1),0.5f,0.5f,0.5f));
    Sphere sphere2(sphere_2_transformation, 10, RGB(0, 255, 0), Material(NormalizedRGB(0,1,0),NormalizedRGB(0,1,0),NormalizedRGB(1,1,1),0.5f,0.5f,0.5f));
    std::vector<Sphere> spheres = {sphere1, sphere2};

    Transformation light_transformation(Vec3(0,25,-50));
    PointLight light(light_transformation, RGB(255, 255, 255), 1.0f);
    std::vector<PointLight> lights = {light};
    AmbientLight ambientLight(RGB(255, 255, 255), 0.1f);

    Scene my_scene(my_cam, spheres, lights, ambientLight);
    Image my_img = my_scene.render();
    sf::Image sfml_img = my_img.renderToSFML();

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(my_cam.resolutionX, my_cam.resolutionY)), "My window");
    sf::Texture texture;
    if (!texture.loadFromImage(sfml_img)) {
        return -1;
    }

    sf::Sprite sprite(texture);

    sprite.setPosition(sf::Vector2f(0,0));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
