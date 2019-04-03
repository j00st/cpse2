#ifndef VIEWGRAPHICAL_HPP
#define VIEWGRAPHICAL_HPP

#include <iostream>

#include "viewController.hpp"
#include "SFML/Graphics.hpp"

class viewGraphical : public viewController {
public:

    viewGraphical();
    ~viewGraphical();
    void draw(int field[9]) override;
    void victory(int player) override;
    char prompt(int currentPlayer) override;

private:

    sf::RenderWindow window;

};

#endif // VIEWGRAPHICAL_HPP
