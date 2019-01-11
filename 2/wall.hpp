#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class wall : public entity {
private:

    sf::RectangleShape rectangle;

public:

	wall(sf::Vector2f position,  sf::Vector2f size, sf::Color color);
	void draw(sf::RenderWindow & window) override;

};

#endif
