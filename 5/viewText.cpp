#include "viewText.hpp"

viewText::viewText() {
    std::cout << "\nStarting text-based tic-tac-toe game.\n" << std::endl;
}

void viewText::draw(int field[9]) {
    std::cout << "\nField numbers:     Current board:\n"
                << "| 0 | 1 | 2 | ---- | " << players[field[0]] << " | " << players[field[1]] << " | " << players[field[2]] << " |\n"
                << "| 3 | 4 | 5 | ---- | " << players[field[3]] << " | " << players[field[4]] << " | " << players[field[5]] << " |\n"
                << "| 6 | 7 | 8 | ---- | " << players[field[6]] << " | " << players[field[7]] << " | " << players[field[8]] << " |\n"
                << std::endl;
}

char viewText::prompt(int currentPlayer) {
    std::cout   << "\nPlayer's turn: " << players[currentPlayer] << '\n'
                << "\nEnter the number of the place you want to sign, or U to undo the last action:" << std::endl;
    char c;
    std::cin    >> c;
    if(c == 'U' || (c > 47 && c < 57)) return c;
    std::cout   << "Character " << c << " is not allowed." << std::endl;
    prompt(currentPlayer);

    return 0;
}

void viewText::victory(int player) {
    std::cout   << "\n========================="
                << "\n= PLAYER " << players[player] << " WON THE GAME ="
                << "\n=   starting new game   ="
                << "\n=========================" <<std::endl;
}

void viewText::tie() {
    std::cout   << "\n========================="
                << "\n=      IT IS A TIE      ="
                << "\n=   starting new game   ="
                << "\n=========================" <<std::endl;
}