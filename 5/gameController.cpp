#include "gameController.hpp"

void gameController::undo() {
    commands.pop_back();
}

const std::vector<command> gameController::getCommands() {
    return commands;
}

const gameController::player gameController::checkWinner() {
    // ...
}

void gameController::switchPlayer() {
    if(currentPlayer == player::O) currentPlayer = player::X;
    else currentPlayer == player::O;
}
