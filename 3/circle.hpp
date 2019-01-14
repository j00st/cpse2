#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class circle : public entity {
private:

    sf::CircleShape shape;

public:

    circle(sf::Vector2f position, sf::Color color, float size);
    
};

#endif
