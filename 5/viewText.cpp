#include "viewText.hpp"

viewText::viewText() {
    std::cout << "\nStarting text-based tic-tac-toe game.\n" << std::endl;
}

void viewText::draw(uint_fast8_t field[9]) {
    std::cout << "\nField numbers:     Current board:\n"
                << "| 0 | 1 | 2 | ---- | " << players[field[0]] << " | " << players[field[1]] << " | " << players[field[2]] << " |\n"
                << "| 3 | 4 | 5 | ---- | " << players[field[3]] << " | " << players[field[4]] << " | " << players[field[5]] << " |\n"
                << "| 6 | 7 | 8 | ---- | " << players[field[6]] << " | " << players[field[7]] << " | " << players[field[8]] << " |\n"
                << std::endl;
    std::cout << "\nEnter the number of the place you want to sign, or U to undo the last action:" << std::endl;
}