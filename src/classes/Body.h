//
// Created by msima on 23.03.2021.
//

#ifndef CLASS_TEST_CPP_BODY_H
#define CLASS_TEST_CPP_BODY_H

#include "SFML/Graphics.hpp"
#include "cmath"

const float G = pow(10, 0);


class Body {
public:
    Body(sf::Vector2f position, sf::Vector2f speed, float mass);

    void Update(float deltaTime);
    void Draw(sf::RenderWindow &window);

    //    getters
    sf::Vector2f getPosition() { return shape.getPosition(); };
    sf::Vector2f getAcceleration() { return acceleration; };
    float getMass() { return mass; };

    //    setters
    void setAcceleration(sf::Vector2f& a) { this->acceleration = a; };

    float Distance(Body &other) {
        return sqrt(
                pow(getPosition().x - other.getPosition().x, 2) +
                pow(getPosition().y - other.getPosition().y, 2)
        );
    };
    void CountAcceleration(Body &other);



protected:
    sf::CircleShape shape;

    sf::Vector2f speed;
    sf::Vector2f acceleration;

    float mass;
};


#endif //CLASS_TEST_CPP_BODY_H
