#include "viewGraphical.hpp"

viewGraphical::viewGraphical() {
    tiles.push_back(new tile(0, sf::Vector2f(20, 20), sf::Vector2f(100, 100), sf::Color::White));
    tiles.push_back(new tile(1, sf::Vector2f(130, 20), sf::Vector2f(100, 100), sf::Color::White));
    tiles.push_back(new tile(2, sf::Vector2f(240, 20), sf::Vector2f(100, 100), sf::Color::White));
    tiles.push_back(new tile(3, sf::Vector2f(20, 130), sf::Vector2f(100, 100), sf::Color::White));
    tiles.push_back(new tile(4, sf::Vector2f(130, 130), sf::Vector2f(100, 100), sf::Color::White));
    tiles.push_back(new tile(5, sf::Vector2f(240, 130), sf::Vector2f(100, 100), sf::Color::White));
    tiles.push_back(new tile(6, sf::Vector2f(20, 240), sf::Vector2f(100, 100), sf::Color::White));
    tiles.push_back(new tile(7, sf::Vector2f(130, 240), sf::Vector2f(100, 100), sf::Color::White));
    tiles.push_back(new tile(8, sf::Vector2f(240, 240), sf::Vector2f(100, 100), sf::Color::White));
    tiles.push_back(new tile(9, sf::Vector2f(20, 350), sf::Vector2f(320, 25), sf::Color::Red));
    window.setPosition(sf::Vector2i(0,0));
}

viewGraphical::~viewGraphical() {
    for(auto & t : tiles){
        delete t;
    }
    window.close();
}

void viewGraphical::draw(int field[9]) {
    window.clear();
    for(auto & t : tiles){
        if(field[t->getPlace()] == 1) t->setColor(sf::Color::Green);
        else if(field[t->getPlace()] == 2) t->setColor(sf::Color::Blue);
        else if(t->getPlace() == 9) t->setColor(sf::Color::Red);
        else t->setColor(sf::Color::White);
        t->draw(window);
    }
    window.display();
}

char viewGraphical::prompt(int currentPlayer) {
    sf::Event event;
    while(window.isOpen()){
        while( window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            else if(event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left ){
                mousePos.x = sf::Mouse::getPosition().x;
                mousePos.y = sf::Mouse::getPosition().y - 65;
                if(mousePos.y > 20 && mousePos.y < 120){
                    if(mousePos.x > 20 && mousePos.x < 120) return '0';
                    if(mousePos.x > 130 && mousePos.x < 230) return '1';
                    if(mousePos.x > 240 && mousePos.x < 340) return '2';
                } else if(mousePos.y > 130 && mousePos.y < 230){
                    if(mousePos.x > 20 && mousePos.x < 120) return '3';
                    if(mousePos.x > 130 && mousePos.x < 230) return '4';
                    if(mousePos.x > 240 && mousePos.x < 340) return '5';
                } else if(mousePos.y > 240 && mousePos.y < 340){
                    if(mousePos.x > 20 && mousePos.x < 120) return '6';
                    if(mousePos.x > 130 && mousePos.x < 230) return '7';
                    if(mousePos.x > 240 && mousePos.x < 340) return '8';
                } else if(mousePos.y > 350 && mousePos.y < 375){
                    if(mousePos.x > 20 && mousePos.x < 340) return 'U';
                }
            }
            sf::sleep(sf::milliseconds(20));
        }
    }
    return 0;
}

void viewGraphical::victory(int player) {
    window.clear();
    if(player == 1){
        for(auto & t : tiles){
            t->setColor(sf::Color::Green);
            t->draw(window);
        }
    } else if(player == 2){
        for(auto & t : tiles){
            t->setColor(sf::Color::Blue);
            t->draw(window);
        }
    }
    window.display();
    sf::sleep(sf::seconds(2));
}

void viewGraphical::tie() {
    window.clear();
    for(auto & t : tiles){
            t->setColor(sf::Color::Yellow);
            t->draw(window);
        }
    window.display();
    sf::sleep(sf::seconds(2));
}