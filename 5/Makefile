objects = main.o

app : $(objects)
		g++ -w -std=c++17 $(objects) -o app -lstdc++

main.o : $(objects)

.PHONY : clean run
clean :
		-rm app $(objects)
run :
		./app