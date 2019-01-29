#ifndef VIEWCONTROLLER_HPP
#define VIEWCONTROLLER_HPP

#include <functional>

class viewController {
public:

    viewController() {};
    virtual void draw(uint_fast8_t field[9]) = 0;

protected:

    char players[3] = { '_', 'X', 'O' };

};

#endif // VIEWCONTROLLER_HPP
