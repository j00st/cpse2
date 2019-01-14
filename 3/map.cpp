#include "map.hpp"
#include "exceptions.hpp"

map::map(std::string filename):
    filename(filename)
{}

map::~map(){
    std::ofstream outfile;
    outfile.open(filename, std::ofstream::out | std::ofstream::trunc);
    for(auto & e : entities){
        outfile << e->print();
        delete e;
    }
}

std::vector<entity*> map::getEntities(){
    return entities;
}

std::ifstream & operator>>(std::ifstream & myInput, sf::Color & rhs){
    std::string s;
    myInput >> s;
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
        if(color.name == s){
            rhs = color.color;
            return myInput;
        }
    }
    if(s == ""){
        throw end_of_file();
    }
    throw unknown_color(s);
}

std::ifstream & operator>>(std::ifstream & myInput, sf::Vector2f & rhs){
    char c;
    if( ! ( myInput >> c )){
        throw end_of_file();
    }
    if( c != '(' ){
        throw invalid_formatting(c);
    }
    if( ! ( myInput >> rhs.x )){
        throw end_of_file();
    }
     if( ! ( myInput >> c )){
        throw end_of_file();
    }
    if( c != ',' ){
        throw invalid_formatting(c);
    }
    if( ! ( myInput >> rhs.y )){
        throw end_of_file();
    }

    if( ! ( myInput >> c )){
        throw end_of_file();
    }
    if( c != ')' ){
        throw invalid_formatting(c);
    }

    return myInput;
}

entity * map::factory(std::ifstream & input){
    sf::Vector2f position;
    std::string name;
    
    input >> name;
    if(name == ""){
        throw end_of_file();
    }

    input >> position;
    if(name == "CIRCLE"){
        sf::Color color;
        uint_fast16_t size;
        input >> color >> size;
        return new circle(position, color, size);
    } else if(name == "RECTANGLE"){
        sf::Color color;
        sf::Vector2f size;
        input >> color >> size;
        return new rectangle(position, color, size);
    } else if(name == "LINE"){
        sf::Color color;
        sf::Vector2f size;
        input >> color >> size;
        return new line(position, color, size);
    } else if(name == "PICTURE"){
        std::string path;
        input >> path;
        return new picture(position, path);
    }
    throw invalid_shape(name);
}

bool map::readEntities(){
    std::ifstream input(filename);
    try{
        for(;;){
            entities.push_back(factory(input));
        }
    }
    catch(end_of_file){
        return true;
    }
}
