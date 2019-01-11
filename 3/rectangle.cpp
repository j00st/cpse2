#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size):
    entity(position, color),
    size(size)
{
    Rectangle.setSize(size);
    Rectangle.setColor(color);
}

void rectangle::draw(sf::RenderWindow & window) {
    Rectangle.setPosition(position);
    window.draw(Rectangle);
}