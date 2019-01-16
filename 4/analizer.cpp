#include "analizer.hpp"

analizer::analizer(std::ifstream & input){
    char temp;
    while(input.get(temp)){
        characters.push_back(temp);
    }
}
