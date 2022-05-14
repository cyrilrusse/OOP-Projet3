
OBJ = main.o controller.o view.o projectile.o model.o character.o
CC = g++
EXEC = Pooyan
FLAGS = `sdl2-config --libs --cflags` -std=c++17 -Wall -Wextra -lm

Pooyan : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

main.o : main.cpp
	$(CC) -c main.cpp $(FLAGS)

controller.o : controller.cpp controller.hpp
	$(CC) -c controller.cpp $(FLAGS)

view.o : view.cpp view.hpp
	$(CC) -c view.cpp $(FLAGS)

projectile.o : projectile.cpp projectile.hpp
	$(CC) -c projectile.cpp $(FLAGS)

model.o : model.cpp model.hpp
	$(CC) -c model.cpp $(FLAGS)

character.o : character.cpp character.hpp
	$(CC) -c character.cpp $(FLAGS)

clean:
	rm $(OBJ) $(EXEC)