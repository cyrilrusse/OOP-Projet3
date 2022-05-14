#include "controller.hpp"
#include "character.hpp"
#include "model.hpp"
#include <iostream>

Controller::Controller(){
    ingame = true;
}



void Controller::handleInputs(){
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){ 
            ingame = false;
            break;
        }
        switch (event.key.keysym.sym){ 
            case SDLK_UP:{
                std::cout << "up" << std::endl;
                // model.mouveMamaPig()
                break;
            }
            case SDLK_DOWN:{
                std::cout<<"down" <<std::endl;
                break;
            }
            case SDLK_SPACE:{
                std::cout << "space" << std::endl;
                break;
            }
            default:
                break;
        }
    }
}