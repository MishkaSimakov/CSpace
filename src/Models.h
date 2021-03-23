//
// Created by msima on 23.03.2021.
//

#ifndef CLASS_TEST_CPP_MODELS_H
#define CLASS_TEST_CPP_MODELS_H

#include "classes/Body.h"

using namespace std;

namespace models {
    Body random_body() {
        sf::Vector2f position;
        position.x = rand() % (int) (constants::WIDTH);
        position.y = rand() % (int) (constants::HEIGHT);

        sf::Vector2f speed;
        speed.x = (rand() % 21 - 10) / 5;
        speed.y = (rand() % 21 - 10) / 5;

        Body body(position, speed, 10);

        return body;
    }

    vector<Body> random(int count = 100) {
        vector<Body> planets;

        for (int i = 0; i < count; ++i) {
            planets.push_back(random_body());
        }

        return planets;
    }

    vector<Body> solar() {
        vector<Body> planets;

        Body sun(sf::Vector2f(100 * 10, 0), sf::Vector2f(0, 0), 100 * 65);
        Body earth(sf::Vector2f(0, 0), sf::Vector2f(0, 2), 100);
        Body moon(sf::Vector2f(100, 0), sf::Vector2f(0, 3), 1);

        planets.push_back(sun);
        planets.push_back(earth);
        planets.push_back(moon);

        return planets;
    }

    vector<Body> black_hole(int count = 100, float mass = pow(10, 5)) {
        vector<Body> planets = random(count);

        Body hole(sf::Vector2f(-1000, -1000), sf::Vector2f(0, 0), mass);
        planets.push_back(hole);

        return planets;
    }
}

#endif //CLASS_TEST_CPP_MODELS_H