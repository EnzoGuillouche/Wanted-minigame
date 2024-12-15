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

        Icon yoshi;
        yoshi.setUp("img/yoshiIcon.png", 1200, 400);
        Icon mario;
        mario.setUp("img/marioIcon.png", 900, 400);
        Icon wario;
        wario.setUp("img/warioIcon.png", 600, 400);
        Icon luigi;
        luigi.setUp("img/luigiIcon.png", 300, 400);

        window.clear();
        window.draw(yoshi.getSprite());
        window.draw(mario.getSprite());
        window.draw(wario.getSprite());
        window.draw(luigi.getSprite());
        window.display();
    }

    return 0;
}