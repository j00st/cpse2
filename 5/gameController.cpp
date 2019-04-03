#include "gameController.hpp"

gameController::gameController() {
    char c;
    for(;;){
        std::cout << "Enter T for textual or G for graphical interface:" << std::endl;
        std::cin >> c;
        switch(charToInput(c)){
            case Textual:
                view = new viewText();
                update();
                break;
            case Graphical:
                view = new viewGraphical();
                update();
                break;
            default:
                std::cout << c << " was not recognised. ";
                break;
        }
    }
}

gameController::input gameController::charToInput(char c){
    if( c == 'T' ) return input::Textual;
    else if( c == 'G' ) return input::Graphical;
    else if( c == 'U' ) return input::Undo;
    else return input::unrecognized;
}

gameController::~gameController() {
    delete view;
}

void gameController::clearField(){
    for(int i = 0; i < 9; i++){
        field[i] = 0;
    }
}

void gameController::undo() {
    //field[commands.back()->getPlace()] = 0;
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
            clearField();
            for(auto & y : commands){
                commands.pop_back();
            }
        }
    }
    if(commands.size() == 9){
        view->tie();
        clearField();
        for(auto & y : commands){
            commands.pop_back();
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
    if(charToInput(c) == Undo){
        if(commands.size() > 0) undo();
        else update();
    } else if(field[c-48] == 0){
        commands.push_back(new command(currentPlayer, int(c - 48)));
    } else update();
    clearField();
    for(auto & x : commands){
        field[x->getPlace()] = x->getPlayer();
    }
    checkWinner();
    switchPlayer();
    update();
}