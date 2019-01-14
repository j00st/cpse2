#include <iostream>
#include <functional>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "entity.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "picture.hpp"
#include "line.hpp"
#include "map.hpp"

int main( int argc, char *argv[] ){
	std::cout << "Starting application 3\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 640 }, "3" };

	while (window.isOpen()) {
		window.clear();

		window.display();

		sf::sleep( sf::milliseconds( 1 ));

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

	std::cout << "Terminating application\n";
	return 0;
}
