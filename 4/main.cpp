#include <iostream>
#include <functional>
#include <string>
#include <fstream>

#include "analizer.hpp"

int main( int argc, char *argv[] ){
	std::ifstream file("bible.txt");
	analizer bible(file);

	return 0;
}
