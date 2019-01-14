#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size):
    entity(shape)
{
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
}
