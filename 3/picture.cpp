#include "picture.hpp"

picture::picture(sf::Vector2f position, sf::Vector2f size, std::string path):
    entity(position),
    size(size),
    path(path)
{
    if(!texture.loadFromFile(path)){
        // EXCEPTION
    }
    sprite.setTexture(texture);
}

void picture::draw(sf::RenderWindow & window) {
    sprite.setPosition(position);
    window.draw(sprite);
}