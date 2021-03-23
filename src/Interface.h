//
// Created by msima on 23.03.2021.
//

#ifndef CLASS_TEST_CPP_INTERFACE_H
#define CLASS_TEST_CPP_INTERFACE_H

#include "SFML/Graphics.hpp"
#include "classes/Body.h"
#include "constants.h"

using namespace std;

namespace interface {
    void draw_grid(sf::RenderWindow &window, sf::View &view) {
        sf::Color grid_color = sf::Color(25, 25, 25);

        sf::Vertex horizontal[] =
                {
                        sf::Vertex(sf::Vector2f(view.getCenter().x - view.getSize().x / 2, 0), grid_color),
                        sf::Vertex(sf::Vector2f(view.getCenter().x + view.getSize().x / 2, 0), grid_color)
                };

        sf::Vertex vertical[] =
                {
                        sf::Vertex(sf::Vector2f(0, view.getCenter().y - view.getSize().y / 2), grid_color),
                        sf::Vertex(sf::Vector2f(0, view.getCenter().y + view.getSize().y / 2), grid_color)
                };

        window.draw(vertical, 2, sf::Lines);
        window.draw(horizontal, 2, sf::Lines);
    }

    void draw_planets(sf::RenderWindow &window, vector<Body> &planets) {
        for (Body &planet : planets) {
            planet.Draw(window);
        }
    }

    void draw_text(sf::RenderWindow &window, sf::View &view, vector<Body> &planets) {
        sf::View infoView;
        float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
        infoView.setSize(constants::HEIGHT * aspectRatio, constants::HEIGHT);

        infoView.setViewport(sf::FloatRect(0.f, 0.f, 0.25f, 0.25f));
        window.setView(infoView);

        const int text_size = 50;
        sf::Vector2f offset(0, 0);

        sf::Font font;
        font.loadFromFile("../assets/fonts/Roboto-Regular.ttf");

        // Фон для текста.
        sf::RectangleShape background(sf::Vector2f(10 * text_size, 3 * text_size));
        background.setFillColor(sf::Color(68, 68, 68));
        background.setPosition(offset);
        window.draw(background);

        // Текст.
        float max_mass = 0.f;
        for (Body &planet : planets) {
            if (planet.getMass() > max_mass) {
                max_mass = planet.getMass();
            }
        }

        vector<string> lines = {
                "Objects count: " + to_string(planets.size()),
                "Max mass: " + to_string((int)max_mass),
        };
        vector<sf::Text> text;

        for (string &line : lines) {
            text.push_back(sf::Text());

            text.back().setFont(font);

            text.back().setString(line);
            text.back().setFillColor(sf::Color::White);
            text.back().setCharacterSize(text_size);
            text.back().setPosition(offset + sf::Vector2f(5, (5 + text_size) * (text.size() - 1) + 5));

            window.draw(text.back());
        }

        window.setView(view);
    }

    void draw_interface(sf::RenderWindow &window, sf::View &view, vector<Body> &planets) {
        draw_grid(window, view);
        draw_planets(window, planets);
        draw_text(window, view, planets);
    }
}

#endif //CLASS_TEST_CPP_INTERFACE_H
