#include "iostream"
#include "SFML/Graphics.hpp"

#include "classes/Body.h"
#include "classes/Player.h"
#include "Models.h"
#include "Interface.h"

using namespace std;


void ResizeView(sf::RenderWindow &window, sf::View &view, Player &player) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(constants::HEIGHT * player.getZoom() * aspectRatio, constants::HEIGHT * player.getZoom());
}

void update_planets(vector<Body> &planets, float deltaTime) {
    for (int i = 0; i < planets.size(); i++) {
        Body *planet1 = &planets[i];
        float radius = planet1->getRadius();

        for (int j = i + 1; j < planets.size(); j++) {
            if (planet1->Distance(planets[j]) < radius + planets[j].getRadius()) {
                Body merged = planet1->Merge(planets[j]);

                planets.erase(planets.begin() + j);
                planets.erase(planets.begin() + i);

                planets.push_back(merged);

                break;
            }
        }
    }

    for (int i = 0; i < planets.size(); i++) {
        Body *planet1 = &planets[i];

        for (int j = i + 1; j < planets.size(); j++) {
            planet1->CountAcceleration(planets[j]);
        }

        planet1->Update(deltaTime);
    }
}


int main(void) {
    srand(time(0));
    vector<Body> planets = models::rotating();

    Player player(sf::Vector2f(0.0f, 0.0f), 1);

    sf::RenderWindow window(sf::VideoMode(constants::WIDTH, constants::HEIGHT), "Space++", sf::Style::Default);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(constants::WIDTH, constants::HEIGHT));


    float deltaTime;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds() * 200;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseWheelScrolled)
                player.ChangeZoom(event);
            else if (event.type == sf::Event::Resized)
                ResizeView(window, view, player);
        }


        player.Update(deltaTime);

        view.setCenter(player.getPosition());
        ResizeView(window, view, player);
        window.setView(view);

        update_planets(planets, deltaTime);

        window.clear();
        interface::draw_interface(window, view, planets);
        window.display();
    }


    return 0;
}