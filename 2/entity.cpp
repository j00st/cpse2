#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include <iostream>

entity::entity(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	position{ position },
    size{ size },
    color{ color }
{}

sf::FloatRect entity::getBoundingBox() {
    return boundingBox;
}

void entity::collide(entity otherEntity)
{
    if(getBoundingBox().left < otherEntity.getBoundingBox().left){
        direction.x *= -1;
    }
    else if(getBoundingBox().left + getBoundingBox().width > otherEntity.getBoundingBox().left + otherEntity.getBoundingBox().width){
        direction.x *= -1;
    }
    else if(getBoundingBox().top+getBoundingBox().height > otherEntity.getBoundingBox().top + otherEntity.getBoundingBox().height){
        direction.y *= -1;
    }
    else if(getBoundingBox().top > otherEntity.getBoundingBox().top){
        direction.y *= -1;
    }
}

void entity::changeColor(){
    if(color == sf::Color::Blue){
        color = sf::Color::Red;
    }
    else{
        color = sf::Color::Blue;
    }
}