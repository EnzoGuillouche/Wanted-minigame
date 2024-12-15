#include <SFML/Graphics.hpp>
#include "icon.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 800), "Wanted!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Icon mario;
        mario.setUp("img/marioIcon.png", 750, 400);
        mario.setPosition(750, 400);

        window.clear();
        window.draw(mario.getSprite());
        window.display();
    }

    return 0;
}