#ifndef TILE_HPP
#define TILE_HPP

#include "SFML/Graphics.hpp"

class tile {
public:

    tile(const int place, sf::Vector2f position, sf::Vector2f size, sf::Color color);
    void draw(sf::RenderWindow & w);
    const int getPlace();
    void setColor(sf::Color c);

private:

    const int place;
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;

};

#endif // TILE_HPP
