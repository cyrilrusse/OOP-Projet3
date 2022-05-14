#include <SDL2/SDL.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "controller.hpp"

int main(){
    srand(time(NULL));
    Controller controller;
    
    while (controller.inGame())
        controller.game();

    controller.endGame();

    return 0;
}