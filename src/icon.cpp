#include <SFML/Graphics.hpp>
#include <string>
#include <random>

int rng() {
    // Pseudo-random direction
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
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
                }
                break;
            case 1: // Move down
                if (pos.y + sprite.getGlobalBounds().height < 800) {
                    pos.y += 1;
                }
                break;
            case 2: // Move left
                if (!pos.x <= 0) {
                    pos.x -= 1;
                }
                break;
            case 3: // Move right
                if (pos.x + sprite.getGlobalBounds().width < 1500) {
                    pos.x += 1;
                }
                break;
            default:
                break;
        }

        sprite.setPosition(pos);
    }
};
