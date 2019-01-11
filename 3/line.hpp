#ifndef _LINE_HPP
#define _LINE_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class line : public entity {
private:

    sf::Vector2f position2;
    sf::Vertex Line[2];

public:

    line(sf::Vector2f position, sf::Color color, sf::Vector2f position2);
    void draw(sf::RenderWindow & window) override;

};

#endif
