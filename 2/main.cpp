#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "entity.hpp"
#include "character.hpp"
#include "wall.hpp"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}

	action(
		entity *thisEntity,
		entity *otherEntity,
		std::function< void() > work
	) :
		condition(
			[ thisEntity, otherEntity ]()->bool {return thisEntity->getBoundingBox().intersects(otherEntity->getBoundingBox()); }
				),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};

int main( int argc, char *argv[] ){
	std::cout << "Starting application 2\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "2" };

	std::vector<entity*> entityList;
	entityList.push_back(new character(sf::Vector2f{160.0, 240.0}, sf::Vector2f{40.0,40.0}, sf::Color::Blue));
	entityList.push_back(new wall(sf::Vector2f{0.0, 0.0}, sf::Vector2f{640.0, 10.0}, sf::Color::Red));
	entityList.push_back(new wall(sf::Vector2f{0.0, 10.0}, sf::Vector2f{10.0, 460.0}, sf::Color::Blue));
	entityList.push_back(new wall(sf::Vector2f{630.0, 10.0}, sf::Vector2f{10.0, 460.0}, sf::Color::Red));
	entityList.push_back(new wall(sf::Vector2f{0.0, 470.0}, sf::Vector2f{640.0, 10.0}, sf::Color::Blue));
	entityList.push_back(new ball(sf::Vector2f{400.0, 300.0}, sf::Vector2f{20.0, 0.0}, sf::Color::Red));

	action actions[] = {
		// action( entityList[5], entityList[4],	[&](){}),
		// action( entityList[5], entityList[0],	[&](){ entityList[5]->bounce('y'); }),
		// action( entityList[5], entityList[1],	[&](){ entityList[5]->bounce('y'); }),
		// action( entityList[5], entityList[2],	[&](){ entityList[5]->bounce('x'); }),
		// action( entityList[5], entityList[3],	[&](){ entityList[5]->bounce('x'); }),
		// action( entityList[5], entityList[4],	[&](){ entityList[5]->bounce('y'); }),
		action( sf::Keyboard::Left,  			[&](){ entityList[0]->move( sf::Vector2f( -10.0,  0.0 )); }),
		action( sf::Keyboard::Right, 			[&](){ entityList[0]->move( sf::Vector2f( +10.0,  0.0 )); }),
		action( sf::Keyboard::Up,    			[&](){ entityList[0]->move( sf::Vector2f(  0.0, -10.0 )); }),
		action( sf::Keyboard::Down,  			[&](){ entityList[0]->move( sf::Vector2f(  0.0, +10.0 )); }),
		action( sf::Keyboard::Escape,			[&](){ window.close(); })
	};

	while (window.isOpen()) {
		window.clear();
		for(auto & entity : entityList){
			for(auto & otherEntity : entityList){
				if(entity != otherEntity){
					auto testcollision = action(entity, otherEntity, [&](){ entity->changeColor(); entity->collide(*otherEntity); });
					testcollision();
				}
			}
			entity->draw(window);
		}
		for( auto & action : actions ){
			action();
		}
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

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

