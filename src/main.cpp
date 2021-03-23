#include "iostream"
#include "SFML/Graphics.hpp"

#include "classes/Body.h"
#include "classes/Player.h"

using namespace std;

const float WIDTH = 500.0f;
const float HEIGHT = 500.0f;


void ResizeView(sf::RenderWindow& window, sf::View& view, Player& player) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(HEIGHT * player.getZoom() * aspectRatio, HEIGHT * player.getZoom());
}

void update_planets(vector<Body>& planets, float deltaTime) {
    for (int i = 0; i < planets.size(); i++) {
        Body *planet1 = &planets[i];

        for (int j = i + 1; j < planets.size(); j++) {
            Body *planet2 = &planets[j];

            planet1->CountAcceleration(*planet2);
        }

        planet1->Update(deltaTime);
    }
}

Body random_body() {
    sf::Vector2f position;
    position.x = rand() % (int)WIDTH;
    position.y = rand() % (int)HEIGHT;

    Body body(position, sf::Vector2f(0, 0), 10);

    return body;
}

int main(void) {
    vector<Body> planets = {};

    Body sun(sf::Vector2f(100 * 10, 0), sf::Vector2f(0, 0), 100 * 65);
    Body earth(sf::Vector2f(0, 0), sf::Vector2f(0, 2), 100);
    Body moon(sf::Vector2f(100, 0), sf::Vector2f(0, 3), 1);

    planets.push_back(sun);
    planets.push_back(earth);
    planets.push_back(moon);


    Player player(sf::Vector2f(0.0f, 0.0f), 1);


    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Space++", sf::Style::Default);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WIDTH, HEIGHT));


    float deltaTime = 0.0f;
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
        for (Body &planet : planets) {
            planet.Draw(window);
        }
        window.display();
    }


    return 0;
}