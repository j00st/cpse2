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

	map level1("level1.txt");
	level1.readEntities();
	std::vector<entity*> entities = level1.getEntities();

	while (window.isOpen()) {
		window.clear();
		for(auto & entity : entities){
			entity->update(window);
		}
		for(auto & entity : entities){
			entity->draw(window);
		}

		window.display();

		sf::sleep( sf::milliseconds( 2 ));

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
