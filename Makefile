
OBJ = main.o
CC = g++
EXEC = Pooyan
FLAGS = `sdl2-config --libs --cflags` -std=c++17 -Wall -Wextra -lm

Pooyan : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

main.o : main.cpp
	$(CC) -c main.cpp $(FLAGS)

player.o : player.cpp player.hpp
	$(CC) -c player.cpp $(FLAGS)


clean:
	rm $(OBJ) $(EXEC)