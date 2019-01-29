#include "viewGraphical.hpp"

viewGraphical::viewGraphical() {
    std::cout << "\nStarting graphical-based tic-tac-toe game.\n";
    std::cout << "Play the game by giving the number of the square you want to sign.\n";
    std::cout << "| 1 | 2 | 3 |\n| 4 | 5 | 6 |\n| 7 | 8 | 9 |\n" << std::endl;
}

void viewGraphical::draw(uint_fast8_t field[9]) {
    std::cout << "draw" << std::endl;
}