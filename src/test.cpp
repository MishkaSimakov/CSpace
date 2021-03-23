//
// Created by msima on 20.03.2021.
//

#include "vector"

#ifndef CLASS_TEST_CPP_BODY_H
#define CLASS_TEST_CPP_BODY_H

using namespace std;

float G = pow(10, -4);


float distance(vector<float> pos1, vector<float> pos2) {
    return sqrt(
            pow(pos1[0] - pos2[0], 2) + pow(pos1[1] - pos2[1], 2)
    );
}

class Body {
public:
    vector<float> position;
    float mass;
    vector<float> speed;

    float radius;
    float density = 5500;

    Body(vector<float> p, vector<float> s, float m) {
        position = p;
        speed = s;
        mass = m;
        radius = cbrt((3 * mass) / (4 * 3.14 * density));
    }


    void gravitate(Body *body) {
        float d = pow(distance(position, body->position), 3);

//        if (d > 250) return;

        float F_x = G * (body->position[0] - position[0]) / d;
        float F_y = G * (body->position[1] - position[1]) / d;

        speed[0] += F_x * body->mass;
        speed[1] += F_y * body->mass;

        body->speed[0] -= F_x * mass;
        body->speed[1] -= F_y * mass;
    }

    void move() {
        position[0] += speed[0];
        position[1] += speed[1];
    }


    bool operator==(Body &other) const {
        if (this == &other) return true;
        else return false;
    }
};


#endif //CLASS_TEST_CPP_BODY_H
