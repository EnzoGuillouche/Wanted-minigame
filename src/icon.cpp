#include <SFML/Graphics.hpp>
#include <bits/unique_ptr.h>
#include <string>
#include <random>

// Variables
sf::Clock movementClock;
int speed = 5;

// Pseudo-random method
std::random_device rd;
std::mt19937 gen(rd());

int rng(int a, int b) {
    std::uniform_int_distribution<> dis(a, b);
    return dis(gen);
}

class Icon {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    int direction;

public:
    void setUp(std::string path, int x, int y) {
        texture.loadFromFile(path);
        sprite.setTexture(texture);
        setPosition(x, y);
        direction = rng(0, 7);
    }

    sf::Sprite& getSprite() {
        return sprite;
    }

    void setPosition(int x, int y) {
        sprite.setPosition(x - (sprite.getGlobalBounds().width / 2), 
                           y - (sprite.getGlobalBounds().height / 2));
    }

    void move() {
        sf::Vector2f pos = sprite.getPosition();

        switch (direction) {
            case 0: // Move up
                if (pos.y > 0) {
                    pos.y -= 1;
                } else {
                    direction = rng(0, 7);
                }
                break;
            case 1: // Move down
                if (pos.y + sprite.getGlobalBounds().height < 800) {
                    pos.y += 1;
                } else {
                    direction = rng(0, 7);
                }
                break;
            case 2: // Move left
                if (pos.x > 0) {
                    pos.x -= 1;
                } else {
                    direction = rng(0, 7);
                }
                break;
            case 3: // Move right
                if (pos.x + sprite.getGlobalBounds().width < 1500) {
                    pos.x += 1;
                } else {
                    direction = rng(0, 7);
                }
                break;
            case 4: // Move up & left
                if (pos.y > 0 && pos.x > 0) {
                    pos.y -= 1;
                    pos.x -= 1;
                } else {
                    direction = rng(0, 7);
                }
                break;
            case 5: // Move up & right
                if (pos.y > 0 && pos.x + sprite.getGlobalBounds().width < 1500) {
                    pos.y -= 1;
                    pos.x += 1;
                } else {
                    direction = rng(0, 7);
                }
                break;
            case 6: // Move down & right
                if (pos.y + sprite.getGlobalBounds().height < 800 && pos.x + sprite.getGlobalBounds().width < 1500) {
                    pos.y += 1;
                    pos.x += 1;
                } else {
                    direction = rng(0, 7);
                }
                break;
            case 7: // Move down & left
                if (pos.y + sprite.getGlobalBounds().height < 800 && pos.x > 0) {
                    pos.y += 1;
                    pos.x -= 1;
                } else {
                    direction = rng(0, 7);
                }
                break;
            default:
                break;
        }

        sprite.setPosition(pos);
    }

    bool hasBeenClicked(sf::Vector2i mousePosition, bool hasClicked) {
        sf::FloatRect bounds = sprite.getGlobalBounds();
        return bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)) && hasClicked;
    }

};

std::vector<std::unique_ptr<Icon>> icons;

void iconCreation(int numberOfIcons, std::string pathOfIcon) { 
    for (size_t i = 0; i < numberOfIcons; i++)
    {
        icons.push_back(std::make_unique<Icon>());
        icons.back()->setUp(pathOfIcon, rng(0, 1500), rng(0, 800));
    }
}

void iconMovementLoop() {
    if (movementClock.getElapsedTime().asMilliseconds() > speed) {
        for (auto& icon : icons) {
            icon->move();
        }
        movementClock.restart();
    }
}

void iconEraser(sf::Vector2i mousePosition, bool hasClicked) {
    icons.erase(
        std::remove_if(icons.begin(), icons.end(),
                        [mousePosition, hasClicked](const std::unique_ptr<Icon>& icon) {
                            return icon->hasBeenClicked(mousePosition, hasClicked);
                        }
                    ),
        icons.end()
    );
}

