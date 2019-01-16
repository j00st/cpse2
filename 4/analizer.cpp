#include "analizer.hpp"

analizer::analizer(std::ifstream & input){
    char temp;
    while(input.get(temp)){
        characters.push_back(temp);
    }
}

uint_fast32_t analizer::get_character_count(){
    return characters.size();
}

uint_fast32_t analizer::get_line_count(){
    return std::count_if(characters.begin(), characters.end(), [](unsigned char c){ return c == '\n'; });
}

uint_fast32_t analizer::get_alphabetic_character_count(){
    return std::count_if(characters.begin(), characters.end(), [](unsigned char c){ return std::isalpha(c); });
}

void analizer::make_lowercase(){
    for_each(
        characters.begin(),
        characters.end(),
        [](unsigned char & c){ c = std::tolower(c); }
    );
}

std::set<std::pair<unsigned char, uint_fast16_t>, analizer::comparator> analizer::map_characters(comparator compFunctor){
    std::map<unsigned char, uint_fast16_t> letterMap;
    for_each(
        characters.begin(),
        characters.end(),
        [&letterMap](unsigned char & c){ if(std::isalpha(c)){ letterMap[c]++; }}
    );
    std::set<std::pair<unsigned char, uint_fast16_t>, comparator> letterSet(letterMap.begin(), letterMap.end(), compFunctor);
    return letterSet;
}

void analizer::print_character_map_alphabetic(){
    std::set<std::pair<unsigned char, uint_fast16_t>, comparator> letterSet;
    letterSet = map_characters([](std::pair<unsigned char, uint_fast16_t> a, std::pair<unsigned char, uint_fast16_t> b){ return a.first < b.first; });
    for(auto i : letterSet){
        std::cout << i.first << " : " << i.second << std::endl;
    }
}

void analizer::print_character_map_descending(){
    std::set<std::pair<unsigned char, uint_fast16_t>, comparator> letterSet;
    letterSet = map_characters([](std::pair<unsigned char, uint_fast16_t> a, std::pair<unsigned char, uint_fast16_t> b){ return a.second > b.second; });
    for(auto i : letterSet){
        std::cout << i.first << " : " << i.second << std::endl;
    }
}
