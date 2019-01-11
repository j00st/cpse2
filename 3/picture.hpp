#ifndef _PICTURE_HPP
#define _PICTURE_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class picture : public entity {
private:

    sf::Vector2f size;
    std::string path;
    sf::Texture texture;
    sf::Sprite sprite;

public:

    picture(sf::Vector2f position, sf::Vector2f size, std::string path);
    void draw(sf::RenderWindow & window) override;
    
};

#endif
