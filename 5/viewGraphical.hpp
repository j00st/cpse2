#ifndef VIEWGRAPHICAL_HPP
#define VIEWGRAPHICAL_HPP

#include <iostream>

#include "viewController.hpp"

class viewGraphical : public viewController {
public:

    viewGraphical();
    void draw(uint_fast8_t field[9]) override;

};;

#endif // VIEWGRAPHICAL_HPP
