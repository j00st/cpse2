#ifndef _MAP_HPP
#define _MAP_HPP

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "entity.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "picture.hpp"
#include "line.hpp"

class map {
private:

	std::vector<entity*> entities;
    std::string filename;
    entity * factory(std::ifstream & input);

public:

	map(std::string filename);
    ~map();
    bool readEntities();
    std::vector<entity*> getEntities();

};

#endif
