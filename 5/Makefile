objects = main.o command.o gameController.o viewController.o viewGraphical.o viewText.o tile.o

app : $(objects)
		g++ -w -std=c++17 $(objects) -o app -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

main.o : $(objects)
gameController.o : gameController.hpp
command.o : command.hpp gameController.o
viewController.o : viewController.hpp gameController.o
viewGraphical.o : viewGraphical.hpp viewController.o
viewText.o : viewText.hpp viewController.o
tile.o : tile.hpp

.PHONY : clean run
clean :
		-rm app $(objects)
run :
		./app