#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include <SDL2/SDL.h>
#include <vector>

#include "view.hpp"
#include "model.hpp"
#include "character.hpp"
#include <iostream>

#define NBR_OF_FPS 30

class Controller{
private:
    SDL_Event event;
    bool ingame;
    View view = View(NBR_OF_FPS);
    Model model = Model(NBR_OF_FPS);
    double time_since_last_wolf;

public:
    //Constructor
    Controller();

    //Access
    bool inGame(){return ingame;}

    void handleInputs();
    void game();
    void endGame();
    void computeObjectsPosition();
    void manageObjects();
    void manageTiming();
    void renderObjects();
    void manageRocks();
};

#endif