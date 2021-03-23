//
// Created by msima on 23.03.2021.
//

#ifndef CLASS_TEST_CPP_BODY_H
#define CLASS_TEST_CPP_BODY_H

#include "SFML/Graphics.hpp"

class Body {
public:
    Body(sf::Vector2f position, sf::Vector2f speed, float mass);

    void Update(float deltaTime);
    void Draw(sf::RenderWindow &window);

protected:
    sf::CircleShape shape;

    sf::Vector2f speed;
    sf::Vector2f acceleration;

    float mass;
};


#endif //CLASS_TEST_CPP_BODY_H
