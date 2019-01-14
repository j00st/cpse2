#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

class entity {
private:

    static entity * currentEntity;
    sf::Vector2f oldMousePos;
    sf::Shape & shape;
    void setPos(sf::Vector2f newPos);

public:

	sf::Vector2f position;
    sf::Color color;

	entity(sf::Shape & shape);
	virtual void draw(sf::RenderWindow & window);
    void update(sf::Vector2f mousePos);
    virtual std::string print();

};

#endif
