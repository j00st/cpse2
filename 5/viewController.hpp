#ifndef VIEWCONTROLLER_HPP
#define VIEWCONTROLLER_HPP

#include <functional>

class viewController {
public:

    viewController() {};
    virtual void draw(int field[9]) = 0;
    virtual char prompt(int currentPlayer) = 0;
    virtual void victory(int player) = 0;
    char players[3] = { '_', 'X', 'O' };

};

#endif // VIEWCONTROLLER_HPP
