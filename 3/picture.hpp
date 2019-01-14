#ifndef _PICTURE_HPP
#define _PICTURE_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class picture : public entity {
private:

    std::string path;
    sf::Texture image;
    sf::RectangleShape shape;

public:

    picture(sf::Vector2f position, std::string path);
    
};

#endif
