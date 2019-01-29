#include "viewText.hpp"

viewText::viewText() {
    std::cout << "\nStarting text-based tic-tac-toe game.\n";
    std::cout << "Play the game by giving the number of the square you want to sign.\n";
    std::cout << "| 0 | 1 | 2 |\n| 3 | 4 | 5 |\n| 6 | 7 | 8 |\n" << std::endl;
    uint_fast8_t temp[9] = { 1,2,0,2,0,1,0,1,1 };
    draw(temp);
}

void viewText::draw(uint_fast8_t field[9]) {
    std::cout << "Enter the number of the field you want to sign.\n";
    std::cout   << "| 0 | 1 | 2 | ---- | " << players[field[0]] << " | " << players[field[1]] << " | " << players[field[2]] << " |\n"
                << "| 3 | 4 | 5 | ---- | " << players[field[3]] << " | " << players[field[4]] << " | " << players[field[5]] << " |\n"
                << "| 6 | 7 | 8 | ---- | " << players[field[6]] << " | " << players[field[7]] << " | " << players[field[8]] << " |\n"
                << std::endl;
}