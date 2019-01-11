#include "line.hpp"

line::line(sf::Vector2f position, sf::Color color, sf::Vector2f position2):
    entity(position, color),
    position2(position2)
{
    Line[0] = sf::Vertex(position, color);
    Line[1] = sf::Vertex(position2, color);
}

void line::draw(sf::RenderWindow & window) {
    window.draw(Line, 2, sf::Lines);
}
