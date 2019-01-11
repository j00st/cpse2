#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include <iostream>

entity::entity(sf::Vector2f position, sf::Color color) :
	position(position),
    color(color)
{}

entity::entity(sf::Vector2f position) :
	position(position)
{}