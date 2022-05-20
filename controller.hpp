#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include <SDL2/SDL.h>
#include <vector>

#include "view.hpp"
#include "model.hpp"
#include "character.hpp"

#define NBR_OF_FPS 30

class Controller{
private:
    SDL_Event event;
    bool ingame, game_lost, keys_pressed[2];
    View view = View(NBR_OF_FPS);
    Model model = Model(NBR_OF_FPS);
    double time_since_last_wolf;    

public:
    //Constructor
    Controller();

    //Access
    bool inGame(){return ingame;}
    bool gameIsLost(){return model.hasLost();};

    void game();
    void gameOver();
    void closeGame();
    void handleInputs();
    void computeObjectsPosition();
    void manageObjects();
    void manageMeat();
    void renderObjects();
    void manageRocks();
};

#endif