//
// Created by msima on 23.03.2021.
//

#include "Body.h"

Body::Body(sf::Vector2f position, sf::Vector2f speed, float mass) {
    this->speed = speed;
    this->mass = mass;

    float radius = 10;
    shape.setRadius(radius);
    shape.setPosition(position);
}

void Body::Update(float deltaTime) {
    sf::Vector2f movement;

    movement = speed * deltaTime;
    shape.move(movement);
}

void Body::Draw(sf::RenderWindow &window) {
    window.draw(shape);
}
