objects = main.o analizer.o

app : $(objects)
		g++ -w -std=c++17 $(objects) -o app -lstdc++

main.o : $(objects)
analizer.o : analizer.hpp

.PHONY : clean run
clean :
		-rm app $(objects)
run :
		./app