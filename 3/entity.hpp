#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include <SFML/Graphics.hpp>

class entity {
protected:

	sf::Vector2f position;
    sf::Color color;
    std::string type;

public:

	entity(sf::Vector2f position, sf::Color color);
    entity(sf::Vector2f position);
	virtual void draw(sf::RenderWindow & window) = 0;

};

#endif
