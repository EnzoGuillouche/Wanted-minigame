#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include <memory>
#include "icon.cpp"

int main()
{
    // Icons are generated here
    iconCreation(2, "img/luigiIcon.png");
    iconCreation(2, "img/marioIcon.png");
    iconCreation(2, "img/warioIcon.png");
    iconCreation(2, "img/yoshiIcon.png");

    sf::RenderWindow window(sf::VideoMode(1500, 800), "Wanted!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || icons.empty())
                window.close();
        }

        iconMovementLoop();
        iconEraser(sf::Mouse::getPosition(window), event.mouseButton.button == sf::Mouse::Left);

        window.clear();
        for (const auto& icon : icons) {
            window.draw(icon->getSprite());
        }
        window.display();
    }

    return 0;
}
