#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class ball : public entity {
private:

	sf::CircleShape circle;

public:

	ball(sf::Vector2f position,  sf::Vector2f size, sf::Color color);
	void draw(sf::RenderWindow & window) override;
	void move(sf::Vector2f delta) override;

};

#endif
