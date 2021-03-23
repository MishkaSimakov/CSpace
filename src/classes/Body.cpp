//
// Created by msima on 23.03.2021.
//

#include "Body.h"
#include "iostream"

Body::Body(sf::Vector2f position, sf::Vector2f speed, float mass) {
    this->speed = speed;
    this->mass = mass;

    float radius = 10;
    shape.setRadius(radius);
    shape.setPosition(position);
}

void Body::Update(float deltaTime) {
    speed += acceleration * deltaTime;
    acceleration = {0, 0};

    sf::Vector2f movement;
    movement = speed * deltaTime;
    shape.move(movement);

//    std::cout << getPosition().x - movement.x << " " << getPosition().y - movement.y << std::endl;
}

void Body::Draw(sf::RenderWindow &window) {
    window.draw(shape);
}

void Body::CountAcceleration(Body& other) {
    float distance_cube = pow(Distance(other), 3);

    sf::Vector2f force = G * (other.getPosition() - getPosition()) / distance_cube;

    sf::Vector2f a = getAcceleration() + force * other.getMass();
    setAcceleration(a);

    a = other.getAcceleration() - force * mass;
    other.setAcceleration(a);
}
