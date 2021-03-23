//
// Created by msima on 23.03.2021.
//

#include "Player.h"

Player::Player(sf::Vector2f position, float zoom) {
    this->position = position;
    this->zoom = zoom;
}

void Player::ChangeZoom(sf::Event &event) {
    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
        zoom = std::max(
                1.0f,
                zoom + event.mouseWheelScroll.delta * ZOOM_SPEED
        );
}

void Player::Update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        speed.x = MOVEMENT_SPEED;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        speed.x = -MOVEMENT_SPEED;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        speed.y = MOVEMENT_SPEED;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        speed.y = -MOVEMENT_SPEED;


    if (speed.x != 0) {
        if (speed.x < 0) speed.x = std::min(0.0f, speed.x + smoothness * deltaTime);
        else speed.x = std::max(0.0f, speed.x - smoothness * deltaTime);
    }

    if (speed.y != 0) {
        if (speed.y < 0) speed.y = std::min(0.0f, speed.y + smoothness * deltaTime);
        else speed.y = std::max(0.0f, speed.y - smoothness * deltaTime);
    }

    position += speed * deltaTime;
}
