#include <iostream>
#include <functional>
#include <string>
#include <fstream>

#include "analizer.hpp"

int main( int argc, char *argv[] ){
	std::ifstream file("bible.txt");
	analizer bible(file);

	std::cout << "\nAnalizing bible.txt" << std::endl;
	std::cout << "Amount of characters: " << bible.get_character_count() << std::endl;
	std::cout << "Amount of lines: " << bible.get_line_count() << std::endl;
	std::cout << "Amount of alphabetic characters: " << bible.get_alphabetic_character_count() << std::endl;

	std::cout << "\nPrint all characters descending alphabetically:" << std::endl;
	bible.print_character_map_alphabetic();
	std::cout << "\nPrint all characters descending on frequency:" << std::endl;
	bible.print_character_map_descending();
	std::cout << "\nPrint 10 most frequent words descending on frequency:" << std::endl;
	bible.print_word_map_descending();

	return 0;
}
