#include "tile.hpp"

tile::tile(const int place, sf::Vector2f position, sf::Vector2f size, sf::Color color):
place(place), position(position), size(size), color(color) {
    shape.setSize(size);
    shape.setPosition(position);
}

void tile::draw(sf::RenderWindow & w){
    shape.setFillColor(color);
    w.draw(shape);
}

const int tile::getPlace(){
    return place;
}

void tile::setColor(sf::Color c){
    color = c;
}