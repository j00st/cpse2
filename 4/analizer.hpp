#ifndef _ANALIZER_HPP
#define _ANALIZER_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

class analizer {
public:
    analizer(std::ifstream & input);
    uint_fast32_t get_character_count();
    uint_fast32_t get_line_count();
    uint_fast32_t get_alphabetic_character_count();
    void make_lowercase();
    void print_character_map_alphabetic();
    void print_character_map_descending();
    void print_word_map_descending();
private:
    typedef std::function<bool(std::pair<unsigned char, uint_fast16_t> a, std::pair<unsigned char, uint_fast16_t> b)> charComparator;
    typedef std::function<bool(std::pair<std::string, uint_fast16_t> a, std::pair<std::string, uint_fast16_t> b)> stringComparator;
    std::set<std::pair<unsigned char, uint_fast16_t>, charComparator> map_characters(charComparator compFunctor);
    std::set<std::pair<std::string, uint_fast16_t>, stringComparator> map_words(stringComparator compFunctor);
    std::vector<unsigned char> characters;
};

#endif
