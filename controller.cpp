#include "controller.hpp"

Controller::Controller(){
    ingame = true;
}

void Controller::handleInputs(){
    while (SDL_PollEvent(&event)){
        switch (event.type){
        case SDL_QUIT:
            ingame = false;
            break;

        default:
            break;
        }
    }
}