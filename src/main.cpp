#include "iostream"
#include "SFML/Graphics.hpp"

#include "Body.h"
#include "Player.h"

using namespace std;

const float WIDTH = 500.0f;
const float HEIGHT = 500.0f;


Body random_body() {
    Body body(sf::Vector2f(0, 0), sf::Vector2f(0, 0), 10);

    return body;
}

int main(void) {
    vector<Body> planets = {};
    planets.push_back(random_body());

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
        }

        player.Update(deltaTime);

        view.setCenter(player.getPosition());
        view.setSize(WIDTH * player.getZoom(), HEIGHT * player.getZoom());
        window.setView(view);

        for (Body &planet : planets) {
            planet.Update(deltaTime);
        }

        window.clear();

        for (Body &planet : planets) {
            planet.Draw(window);
        }

        window.display();
    }


    return 0;
}