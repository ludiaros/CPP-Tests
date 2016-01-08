#include <SFML/Graphics.hpp>

#include "Light.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode(600, 600), "Lights with BlendMode");

    Light light1(200, 2, 255);
    light1.setPosition(300, 100);

    Light light2(200, 1, 255);
    light2.setPosition(100, 100);

    sf::RenderTexture overlay;
    overlay.create(window.getSize().x, window.getSize().y);

    sf::Sprite drawOverlay;
    drawOverlay.setTexture(overlay.getTexture());
    drawOverlay.setTextureRect(drawOverlay.getTextureRect());

    sf::RectangleShape square1 = sf::RectangleShape(sf::Vector2f(200, 200));
    square1.setPosition(50, 50);
    square1.setFillColor(sf::Color(255, 0, 0, 255));

    sf::RectangleShape square2 = sf::RectangleShape(sf::Vector2f(200, 200));
    square2.setPosition(350, 50);
    square2.setFillColor(sf::Color(0, 255, 0, 255));

    sf::RectangleShape square3 = sf::RectangleShape(sf::Vector2f(200, 200));
    square3.setPosition(50, 350);
    square3.setFillColor(sf::Color(0, 0, 255, 255));

    sf::RectangleShape square4 = sf::RectangleShape(sf::Vector2f(200, 200));
    square4.setPosition(350, 350);
    square4.setFillColor(sf::Color(128, 128, 128, 128));

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window.close(); }
        }

        light2.setPosition(sf::Mouse::getPosition(window).x, window.getSize().y - sf::Mouse::getPosition(window).y);

        window.clear();

        window.draw(square1);
        window.draw(square2);
        window.draw(square3);
        window.draw(square4);

        overlay.clear(sf::Color::Black);//(0,0,0,0));

        overlay.draw(light1, sf::BlendAdd);
        overlay.draw(light2, sf::BlendAdd);

        drawOverlay.setTexture(overlay.getTexture());

        window.draw(drawOverlay, sf::BlendMultiply);

        window.display();
    }
}
