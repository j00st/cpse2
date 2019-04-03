#ifndef VIEWGRAPHICAL_HPP
#define VIEWGRAPHICAL_HPP

#include <iostream>

#include "viewController.hpp"
#include "SFML/Graphics.hpp"
#include "tile.hpp"

class viewGraphical : public viewController {
public:

    viewGraphical();
    ~viewGraphical();
    void draw(int field[9]) override;
    void victory(int player) override;
    void tie() override;
    char prompt(int currentPlayer) override;

private:

    sf::RenderWindow window{ sf::VideoMode{ 500, 500 }, "tic-tac-toe"};
    std::vector<tile*> tiles;
    sf::Vector2i mousePos;

};

#endif // VIEWGRAPHICAL_HPP
