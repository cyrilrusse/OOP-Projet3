#include "controller.hpp"
#include "character.hpp"

Controller::Controller(){
    ingame = true;
}



void Controller::handleInputs(){
    while (SDL_PollEvent(&event)){
        switch (event.type){
        case SDL_QUIT:
            ingame = false;
            break;
        case SDLK_UP:
            

        default:
            break;
        }
    }
}