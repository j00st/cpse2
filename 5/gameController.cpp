#include "gameController.hpp"

gameController::gameController() {
    char c;
    for(;;){
        std::cout << "Enter T for textual or G for graphical interface:" << std::endl;
        std::cin >> c;
        if(c == 'T') {
            view = new viewText();
            break;
        } else if(c == 'G') {
            view = new viewGraphical();
            break;
        } else {
            std::cout << c << " was not recognised.";
        }
    }
}

gameController::~gameController() {
    delete view;
}

void gameController::undo() {
    commands.pop_back();
}

std::vector<command*> gameController::getCommands() {
    return commands;
}

const uint_fast8_t gameController::checkWinner() {
    return 0;
}

void gameController::switchPlayer() {
    if(currentPlayer == 1) currentPlayer = 2;
    else currentPlayer == 1;
}

void gameController::update() {
    checkWinner();
    for(auto & x : commands){
        field[x->getPlace()] = x->getPlayer();
    }
}
