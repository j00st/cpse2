objects = main.o ball.o entity.o wall.o character.o

app : $(objects)
		g++ -std=c++17 $(objects) -o app -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

main.o : $(objects)
entity.o : entity.hpp
ball.o : ball.hpp entity.o
wall.o : wall.hpp entity.o
character.o : character.hpp entity.o

.PHONY : clean run
clean :
		-rm app $(objects)
run :
		./app