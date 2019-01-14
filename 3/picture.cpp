#include "picture.hpp"
#include "exceptions.hpp"

picture::picture(sf::Vector2f position, std::string path):
    entity(shape),
    path(path)
{
    if(!image.loadFromFile(path)){
        throw file_not_found(path);
    }
    shape.setPosition(position);
    shape.setSize((sf::Vector2f)image.getSize());
    shape.setTexture(&image);
}
