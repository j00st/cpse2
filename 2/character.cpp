#include <SFML/Graphics.hpp>
#include "character.hpp"

character::character(sf::Vector2f position,  sf::Vector2f size, sf::Color color) :
	entity(position, size, color)
{
	rectangle.setSize(size);
}

void character::draw(sf::RenderWindow & window)
{
	rectangle.setFillColor(color);
	rectangle.setPosition(position);
	boundingBox = rectangle.getGlobalBounds();
	window.draw(rectangle);
}

void character::move(sf::Vector2f delta)
{
	rectangle.setPosition(position += delta);
}
