objects = main.o circle.o entity.o rectangle.o picture.o line.o map.o

app : $(objects)
		g++ -w -std=c++17 $(objects) -o app -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

main.o : $(objects) exceptions.hpp
map.o : map.hpp
entity.o : entity.hpp
circle.o : circle.hpp entity.o
rectangle.o : rectangle.hpp entity.o
picture.o : picture.hpp entity.o
line.o : line.hpp entity.o

.PHONY : clean run
clean :
		-rm app $(objects)
run :
		./app