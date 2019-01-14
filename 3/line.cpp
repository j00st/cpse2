#include "line.hpp"

line::line(sf::Vector2f position, sf::Color color, sf::Vector2f size):
    entity( shape )
{
    shape.setPosition(position);
    shape.setFillColor(color);
    shape.setSize(size);
}

void line::draw(sf::RenderWindow & window) {
    Line[0] = sf::Vertex(shape.getPosition(), shape.getFillColor());
    Line[1] = sf::Vertex(shape.getPosition() + shape.getSize(), shape.getFillColor());
    window.draw(Line, 2, sf::Lines);
}
