#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.hpp"

entity::entity(sf::Shape & shape) :
	shape(shape)
{
    position = shape.getPosition();
}

entity * entity::currentEntity = NULL;

void entity::setPos(sf::Vector2f newPos){
    shape.setPosition(newPos);
    position = newPos;
}

void entity::update(sf::Vector2f mousePos){
    if(currentEntity == NULL && shape.getGlobalBounds().contains(mousePos)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            currentEntity = this;
        } else{
            currentEntity = NULL;
        }
    } else{
        currentEntity = NULL;
    }
    if(currentEntity == this){
        setPos(shape.getPosition() + ((sf::Vector2f)mousePos - oldMousePos));
    }
    oldMousePos = mousePos;
}

void entity::draw(sf::RenderWindow & window){
    window.draw(shape);
}

std::string entity::print(){
    std::string s;
    s = std::string{"VOID ("} + std::to_string(position.x) + "," + std::to_string(position.y) + ") ";
    return s;
}
