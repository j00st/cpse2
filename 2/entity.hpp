#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include <SFML/Graphics.hpp>

class entity {
protected:

	sf::Vector2f position;
    sf::Vector2f direction;
	sf::Vector2f size;
    sf::Color color;
    sf::FloatRect boundingBox;

public:

	entity(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	virtual void draw(sf::RenderWindow & window) {}
    virtual void move(sf::Vector2f delta) {}
    void collide(entity otherEntity);
    sf::FloatRect getBoundingBox();
    void changeColor();

};

#endif
