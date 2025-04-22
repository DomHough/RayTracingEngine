#include <iostream>

#include "include/Camera.h"
#include "include/Cube.h"
#include "include/Scene.h"
#include <SFML/Graphics.hpp>

int main() {
    Transformation camera_transformation(Vec3(0, 0, -50), Rotation(0, 0, 0), Vec3(1, 1, 1));
    Camera my_cam(camera_transformation, 256, 256, 90);

    Transformation sphere_transformation(Vec3(0,0,-100), Rotation(0, 0, 0), Vec3(1, 1, 1));
    Sphere my_sphere(sphere_transformation, 10, RGB(255, 0, 0));
    Scene my_scene(my_cam, my_sphere);
    Image my_img = my_scene.render();
    sf::Image sfml_img = my_img.renderToSFML();

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(my_cam.resolutionX, my_cam.resolutionY)), "My window");
    sf::Texture texture;
    if (!texture.loadFromImage(sfml_img)) {
        return -1;
    }

    sf::Sprite sprite(texture);

    sprite.setPosition(sf::Vector2f(0,0));

    window.clear();
    window.draw(sprite);
    window.display();

    sf::sleep(sf::seconds(5));

    window.close();

    return 0;
}
