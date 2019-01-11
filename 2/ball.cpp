#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball(sf::Vector2f position,  sf::Vector2f size, sf::Color color) :
	entity(position, size, color)
{
	circle.setPosition(position);
	direction = sf::Vector2f(3.0, 3.0);
	circle.setRadius(size.x);
}

void ball::draw(sf::RenderWindow & window)
{
	circle.setFillColor(color);
	move(direction);
	boundingBox = circle.getGlobalBounds();
	window.draw(circle);
}

void ball::move(sf::Vector2f delta)
{
	circle.setPosition(position += delta);
}
