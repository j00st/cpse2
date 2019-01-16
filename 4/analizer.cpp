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
    return std::count_if(characters.begin(), characters.end(), [](unsigned char c){ return c == '\n'; }) + 1;   // +1 for last line
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

std::set<std::pair<unsigned char, uint_fast16_t>, analizer::charComparator> analizer::map_characters(charComparator compFunctor){
    make_lowercase();
    std::map<unsigned char, uint_fast16_t> letterMap;
    for_each(
        characters.begin(),
        characters.end(),
        [&letterMap](unsigned char & c){ if(std::isalpha(c)){ letterMap[c]++; }}
    );
    std::set<std::pair<unsigned char, uint_fast16_t>, charComparator> letterSet(letterMap.begin(), letterMap.end(), compFunctor);
    return letterSet;
}

std::set<std::pair<std::string, uint_fast16_t>, analizer::stringComparator> analizer::map_words(stringComparator compFunctor){
    make_lowercase();
    std::map<std::string, uint_fast16_t> wordMap;
    std::string word;
    for_each(
        characters.begin(),
        characters.end(),
        [&wordMap, &word](unsigned char & c){
            if(std::isalpha(c)){
                word += c;
            } else if(word.size() > 0){
                wordMap[word]++;
                word = "";
            }
        }
    );
    std::set<std::pair<std::string, uint_fast16_t>, stringComparator> wordSet(wordMap.begin(), wordMap.end(), compFunctor);
    return wordSet;
}

void analizer::print_character_map_alphabetic(){
    std::set<std::pair<unsigned char, uint_fast16_t>, charComparator> letterSet;
    letterSet = map_characters([](std::pair<unsigned char, uint_fast16_t> a, std::pair<unsigned char, uint_fast16_t> b){ return a.first < b.first; });
    for(auto i : letterSet){
        std::cout << i.first << " : " << i.second << std::endl;
    }
}

void analizer::print_character_map_descending(){
    std::set<std::pair<unsigned char, uint_fast16_t>, charComparator> letterSet;
    letterSet = map_characters([](std::pair<unsigned char, uint_fast16_t> a, std::pair<unsigned char, uint_fast16_t> b){ return a.second > b.second; });
    for(auto i : letterSet){
        std::cout << i.first << " : " << i.second << std::endl;
    }
}

void analizer::print_word_map_descending(){
    std::set<std::pair<std::string, uint_fast16_t>, stringComparator> wordSet;
    wordSet = map_words([](std::pair<std::string, uint_fast16_t> a, std::pair<std::string, uint_fast16_t> b){ return a.second > b.second; });
    int count = 0;
    for(auto i : wordSet){
        std::cout << i.first << " : " << i.second << std::endl;
        count++;
        if(count >= 10) break;
    }
}
