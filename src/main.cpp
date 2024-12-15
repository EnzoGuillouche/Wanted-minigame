#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "icon.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 800), "Wanted!");
    Icon luigi;
    luigi.setUp("img/luigiIcon.png", 750, 400);

    sf::Clock clock;
    int speed = 5;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (clock.getElapsedTime().asMilliseconds() > speed) {
            luigi.move();
            clock.restart();
        }

        window.clear();
        window.draw(luigi.getSprite());
        window.display();
    }

    return 0;
}