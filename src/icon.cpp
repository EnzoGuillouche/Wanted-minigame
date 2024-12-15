#include <SFML/Graphics.hpp>
#include <string>
#include <random>

int rng() {
    // Pseudo-random direction
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 7);
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
        sprite.setPosition(x, y);
        direction = rng();
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
                if (!pos.y <= 0) {
                    pos.y -= 1;
                } else {
                    direction = rng();
                }
                break;
            case 1: // Move down
                if (pos.y + sprite.getGlobalBounds().height < 800) {
                    pos.y += 1;
                } else {
                    direction = rng();
                }
                break;
            case 2: // Move left
                if (!pos.x <= 0) {
                    pos.x -= 1;
                } else {
                    direction = rng();
                }
                break;
            case 3: // Move right
                if (pos.x + sprite.getGlobalBounds().width < 1500) {
                    pos.x += 1;
                } else {
                    direction = rng();
                }
                break;
            case 4: // Move up & left
                if (!pos.y <= 0 && !pos.x <= 0) {
                    pos.y -= 1;
                    pos.x -= 1;
                } else {
                    direction = rng();
                }
                break;
            case 5: // Move up & right
                if (!pos.y <= 0 && pos.x + sprite.getGlobalBounds().width < 1500) {
                    pos.y -= 1;
                    pos.x += 1;
                } else {
                    direction = rng();
                }
                break;
            case 6: // Move down & right
                if (pos.y + sprite.getGlobalBounds().height < 800 && pos.x + sprite.getGlobalBounds().width < 1500) {
                    pos.y += 1;
                    pos.x += 1;
                } else {
                    direction = rng();
                }
                break;
            case 7: // Move down & left
                if (pos.y + sprite.getGlobalBounds().height < 800 && !pos.x <= 0) {
                    pos.y += 1;
                    pos.x -= 1;
                } else {
                    direction = rng();
                }
                break;
            default:
                break;
        }

        sprite.setPosition(pos);
    }
};
