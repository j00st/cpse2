#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class rectangle : public entity {
private:

    sf::RectangleShape shape;

public:

    rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size);
    std::string print() override;
    
};

#endif
