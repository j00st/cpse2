#include "gameController.hpp"

gameController::gameController() {
    char c;
    for(;;){
        std::cout << "Enter T for textual or G for graphical interface:" << std::endl;
        std::cin >> c;
        if(c == 'T') {
            view = new viewText();
            update();
            break;
        } else if(c == 'G') {
            view = new viewGraphical();
            update();
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
    field[commands.back()->getPlace()] = 0;
    commands.pop_back();
}

std::vector<command*> gameController::getCommands() {
    return commands;
}

void gameController::checkWinner() {
    std::array<std::array<int, 3>, 8> patterns = { {
        { { 0, 1, 2 } }, { { 3, 4, 5 } }, { { 6, 7, 8 } },
        { { 0, 3, 6 } }, { { 1, 4, 7 } }, { { 2, 5, 8 } },
        { { 0, 4, 8 } }, { { 2, 4, 6 } }
    } };
    for( int x = 0; x < 8; x++ ){
        if( currentPlayer == field[patterns[x][0]] &&
            currentPlayer == field[patterns[x][1]] &&
            currentPlayer == field[patterns[x][2]] ) {
            view->victory(currentPlayer);
            for(auto & y : commands){
                undo();
            }
        }
    }
}

void gameController::switchPlayer() {
    if(currentPlayer == 1) currentPlayer = 2;
    else currentPlayer = 1;
}

void gameController::update() {
    view->draw(field);
    char c = view->prompt(currentPlayer);
    if(c == 'U'){
        if(commands.size() > 0) undo();
        else update();
    } else if(field[c-48] == 0){
        commands.push_back(new command(currentPlayer, int(c - 48)));
    } else update();
    for(auto & x : commands){
        field[x->getPlace()] = x->getPlayer();
    }
    checkWinner();
    switchPlayer();
    update();
}
