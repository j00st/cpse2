#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.hpp"

entity::entity(sf::Shape & shape) :
	shape(shape)
{
    position = shape.getPosition();
}

void entity::setPos(sf::Vector2f newPos){
    shape.setPosition(newPos);
    position = newPos;
}

void entity::update(sf::RenderWindow & window){
    if(shape.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window))){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            selected = true;
        } else{
            selected = false;
        }
    } else{
        selected = false;
    }

    if(selected){
        setPos(shape.getPosition() + ((sf::Vector2f)sf::Mouse::getPosition(window) - oldMousePos));
        oldMousePos = (sf::Vector2f)sf::Mouse::getPosition(window);
    } else{
        oldMousePos = (sf::Vector2f)sf::Mouse::getPosition(window);
    }
}

void entity::draw(sf::RenderWindow & window){
    window.draw(shape);
}

std::string entity::print(){
    std::string s;
    s = std::string{"VOID ("} + std::to_string(position.x) + "," + std::to_string(position.y) + ") ";
    return s;
}
