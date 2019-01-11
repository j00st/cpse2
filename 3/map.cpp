#include "map.hpp"

map::map(std::ifstream & input):
    input(input) {
    
}

map::~map(){

}

std::vector<entity*> map::getEntities(){

}

std::ifstream & operator>>( std::ifstream & input, sf::Color & rhs){
    // colors
}

std::ifstream & operator>>( std::ifstream & input, sf::Image & rhs){
    // picture
}

std::ifstream & operator>>( std::ifstream & input, sf::Vector2f & rhs){
    // coordinates
}

std::ifstream & operator<<( std::ifstream & input, sf::Vector2f & rhs){
    // coordinates
}