#include "circle.hpp"

circle::circle(sf::Vector2f position, sf::Color color, float size):
    entity( shape )
{
    shape.setPosition(position);
    shape.setRadius(size);
    shape.setFillColor(color);
}

std::string circle::print(){
    std::string s;
    s = std::string{"CIRCLE ("} + std::to_string((int)shape.getPosition().x) + "," + std::to_string((int)shape.getPosition().y) + ") ";
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
    s += " " + std::to_string((int)shape.getRadius()) + "\n";
    return s;
}