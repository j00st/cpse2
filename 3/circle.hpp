#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class circle : public entity {
private:

    float size;
    sf::CircleShape Circle;

public:

    circle(sf::Vector2f position, sf::Color color, float size);
    void draw(sf::RenderWindow & window) override;
    
};

#endif
