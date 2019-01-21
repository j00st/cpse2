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

    const enum class player{ X, O };

    gameController() {};
    void undo();
    const std::vector<command> getCommands();

private:

    std::vector<command> commands;
    player currentPlayer = player::O;

    const player checkWinner();
    void switchPlayer();

};

#endif // GAMECONTROLLER_HPP
