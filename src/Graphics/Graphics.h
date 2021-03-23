#ifndef CLASS_TEST_CPP_GRAPHICS_H
#define CLASS_TEST_CPP_GRAPHICS_H

#include "SFML/Graphics.hpp"
#include "cmath"
#include "vector"

using namespace std;

class GraphicsService {
public:
    float zoom;

    int width;
    int height;

    int offset_x;
    int offset_y;

    GraphicsService(vector<int> size = {1000, 1000}, float zoom = 1) {
        GraphicsService::zoom = zoom;

        width = size[0];
        height = size[1];

        offset_x = width / 2;
        offset_y = height / 2;
    }

    float transformPosition(float pos, bool is_x) {
        if (is_x) return pos / zoom + offset_x;

        return pos / zoom + offset_y;
    }

    void start() {
        sf::RenderWindow window(sf::VideoMode(width, height), "Space++", sf::Style::Close);
        window.setActive();
    }

    void handleEvents(sf::Window window) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseWheelMoved) {
                if (event.mouseWheel.delta > 0) {
                    zoom /= 1.1;
//                    offset_x = width - event.mouseButton.x * zoom;
//                    offset_y = height - event.mouseButton.y * zoom;
                } else zoom *= 1.1;
            }

            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    offset_y += zoom * 5;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    offset_y -= zoom * 5;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    offset_x += zoom * 5;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    offset_x -= zoom * 5;
                }
            }
        }
    }

    void createWindow() {

    }
};

#endif //CLASS_TEST_CPP_GRAPHICS_H
