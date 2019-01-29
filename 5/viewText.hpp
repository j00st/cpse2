#ifndef VIEWTEXT_HPP
#define VIEWTEXT_HPP

#include <iostream>

#include "viewController.hpp"

class viewText : public viewController {
public:

    viewText();
    void draw(uint_fast8_t field[9]) override;

};

#endif // VIEWTEXT_HPP
