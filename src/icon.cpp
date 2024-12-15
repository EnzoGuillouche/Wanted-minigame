#include <SFML/Graphics.hpp>
#include <string>

class Icon {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    void setUp(std::string path, int x, int y) {
        texture.loadFromFile(path);
        sprite.setTexture(texture);
        sprite.setPosition(0, 0);
    }

    sf::Sprite getSprite() {
        return sprite;
    }

    void setPosition(int x, int y) {
        sprite.setPosition(x-(sprite.getGlobalBounds().width/2), y-(sprite.getGlobalBounds().height/2));
    }

};
