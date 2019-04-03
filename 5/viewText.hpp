#ifndef VIEWTEXT_HPP
#define VIEWTEXT_HPP

#include <iostream>

#include "viewController.hpp"

class viewText : public viewController {
public:

    viewText();
    void draw(int field[9]) override;
    void victory(int player) override;
    char prompt(int currentPlayer) override;

};

#endif // VIEWTEXT_HPP
