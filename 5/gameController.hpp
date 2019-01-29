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
    // std::vector<command*> getCommands();

private:

    // std::vector<command*> commands;
    uint_fast8_t currentPlayer = 1;
    viewController * view = nullptr;
    uint_fast8_t field[9] = { 0 };

    const uint_fast8_t checkWinner();
    void switchPlayer();

};

#endif // GAMECONTROLLER_HPP
