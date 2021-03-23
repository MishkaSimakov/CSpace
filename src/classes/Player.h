//
// Created by msima on 23.03.2021.
//

#ifndef CLASS_TEST_CPP_PLAYER_H
#define CLASS_TEST_CPP_PLAYER_H

#include "SFML/Graphics.hpp"
#include "iostream"

const float MOVEMENT_SPEED = 5;
const float ZOOM_SPEED = -0.25;

class Player {
public:
    Player(sf::Vector2f position, float zoom);

    void ChangeZoom(sf::Event &event);
    void Update(float deltaTime);

    const sf::Vector2f &getPosition() { return position; };
    float getZoom() { return zoom; };

protected:
    sf::Vector2f position;
    sf::Vector2f speed = {0.0f, 0.0f};

    float zoom;
    const float smoothness = 1 / 7.5f;
};


#endif //CLASS_TEST_CPP_PLAYER_H
