#include <SFML/Graphics.hpp>
#include "wall.hpp"

wall::wall(sf::Vector2f position,  sf::Vector2f size, sf::Color color) :
	entity(position, size, color)
{
	rectangle.setSize(size);
}

void wall::draw(sf::RenderWindow & window)
{
	rectangle.setFillColor(color);
	rectangle.setPosition(position);
	boundingBox = rectangle.getGlobalBounds();
	window.draw(rectangle);
}
