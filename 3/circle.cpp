#include "circle.hpp"

circle::circle(sf::Vector2f position, sf::Color color, float size):
    entity(position, color),
    size(size)
{
    Circle.setRadius(size);
    Circle.setColor(color);
}

void circle::draw(sf::RenderWindow & window) {
    Circle.setPosition(position);
    window.draw(Circle);
}