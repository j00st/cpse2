#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.hpp"

entity::entity(sf::Shape & shape) :
	shape(shape)
{}

void entity::update(sf::RenderWindow & window){
    if(shape.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window))){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            selected = true;
        }
    }
}

void entity::draw(sf::RenderWindow & window){
    window.draw(shape);
}