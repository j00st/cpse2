objects = main.o

app : $(objects)
		g++ -w -std=c++17 $(objects) -o app -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

main.o : $(objects)

.PHONY : clean run
clean :
		-rm app $(objects)
run :
		./app