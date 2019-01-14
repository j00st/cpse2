#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

class entity {
private:

    bool selected = false;
    sf::Vector2f oldMousePos;
    sf::Shape & shape;

protected:

	sf::Vector2f position;
    sf::Color color;

public:

	entity(sf::Shape & shape);
	virtual void draw(sf::RenderWindow & window);
    void update(sf::RenderWindow & window);

};

#endif
