#ifndef _MAP_HPP
#define _MAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "picture.hpp"
#include "line.hpp"

class map {
protected:

	std::vector<entity*> entityList;
    std::ifstream & input;

public:

	map(std::ifstream & input);
    ~map();
    std::vector<entity*> getEntities();

};

#endif
