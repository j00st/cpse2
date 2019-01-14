#include "circle.hpp"

circle::circle(sf::Vector2f position, sf::Color color, float size):
    entity( shape )
{
    shape.setPosition(position);
    shape.setRadius(size);
    shape.setFillColor(color);
}