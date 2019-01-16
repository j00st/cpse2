#ifndef _ANALIZER_HPP
#define _ANALIZER_HPP

#include <vector>
#include <iostream>
#include <fstream>


class analizer {
public:
    analizer(std::ifstream & input);
private:
    std::vector<unsigned char> characters;
};

#endif
