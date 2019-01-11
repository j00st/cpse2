#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class character : public entity {
private:

    sf::RectangleShape rectangle;

public:

	character(sf::Vector2f position,  sf::Vector2f size, sf::Color color);
	void draw(sf::RenderWindow & window) override;
	void move(sf::Vector2f delta) override;

};

#endif
