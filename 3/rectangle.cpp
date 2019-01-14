#include "rectangle.hpp"
#include <string>
#include <iostream>

rectangle::rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size):
    entity(shape)
{
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
}

std::string rectangle::print(){
    std::string s;
    s = std::string{"RECTANGLE ("} + std::to_string((int)shape.getPosition().x) + "," + std::to_string((int)shape.getPosition().y) + ") ";
    const struct { const char * name; sf::Color color; } colors[]{
        { "BLACK", sf::Color::Black },
        { "BLUE", sf::Color::Blue },
        { "CYAN", sf::Color::Cyan },
        { "GREEN", sf::Color::Green },
        { "MAGENTA", sf::Color::Magenta },
        { "RED", sf::Color::Red },
        { "TRANSPARENT", sf::Color::Transparent },
        { "WHITE", sf::Color::White },
        { "YELLOW", sf::Color::Yellow }
    };
    for(auto const & color : colors){
        if(color.color == shape.getFillColor()){
            s += color.name;
        }
    }
    s += " (" + std::to_string((int)shape.getSize().x) + "," + std::to_string((int)shape.getSize().y) + ") \n";
    return s;
}
