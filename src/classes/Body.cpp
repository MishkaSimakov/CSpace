//
// Created by msima on 23.03.2021.
//

#include "Body.h"
#include "iostream"

Body::Body(sf::Vector2f position, sf::Vector2f speed, float mass) {
    this->speed = speed;
    this->mass = mass;

    float radius = cbrt(mass / 4);
    shape.setRadius(radius);
    shape.setPosition(position);
}

void Body::Update(float deltaTime) {
    speed += acceleration * deltaTime;
    acceleration = {0, 0};

    sf::Vector2f movement;
    movement = speed * deltaTime;
    shape.move(movement);
}

void Body::Draw(sf::RenderWindow &window) {
    window.draw(shape);
}

Body Body::Merge(Body &other) {
    sf::Vector2f position =
            (getPosition() * getMass() + other.getPosition() * other.getMass()) / (getMass() + other.getMass());
    sf::Vector2f spd = (getSpeed() * getMass() + other.getSpeed() * other.getMass()) / (getMass() + other.getMass());

    Body merged(position, spd, getMass() + other.getMass());

    return merged;
}

void Body::CountAcceleration(Body &other) {
    float distance = Distance(other);

    sf::Vector2f force = constants::G * (other.getPosition() - getPosition()) / (float) pow(distance, 3);

    sf::Vector2f a = getAcceleration() + force * other.getMass();
    setAcceleration(a);

    a = other.getAcceleration() - force * mass;
    other.setAcceleration(a);
}
