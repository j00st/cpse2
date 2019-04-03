#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <vector>
#include <functional>

#include "viewController.hpp"
#include "viewText.hpp"
#include "viewGraphical.hpp"
#include "command.hpp"

class gameController {
public:

    gameController();
    ~gameController();
    void undo();
    std::vector<command*> getCommands();
    void update();

private:

    std::vector<command*> commands;
    int currentPlayer = 1;
    viewController * view = nullptr;
    int field[9] = { 0 };

    void checkWinner();
    void switchPlayer();

};

#endif // GAMECONTROLLER_HPP
