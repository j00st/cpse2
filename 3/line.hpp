#ifndef _LINE_HPP
#define _LINE_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class line : public entity {
private:

    sf::Vector2f size;
    sf::Vertex Line[2];
    sf::RectangleShape shape;

public:

    line(sf::Vector2f position, sf::Color color, sf::Vector2f size);
    void draw(sf::RenderWindow & window) override;
    std::string print() override;

};

#endif
