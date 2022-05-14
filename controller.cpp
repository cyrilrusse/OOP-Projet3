#include "controller.hpp"

Controller::Controller(){
    ingame = true;
}

void Controller::handleInputs(){
    bool mama_moved = false;
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){ 
            ingame = false;
            break;
        }
        switch (event.key.keysym.sym){ 
            case SDLK_UP:
                model.moveMamaPig(1);
                mama_moved = true;
                break;
            case SDLK_DOWN:
                model.moveMamaPig(-1);
                mama_moved = true;
                break;
            case SDLK_SPACE:
                
            default:
                break;
        }
    }
    if(!mama_moved)
        model.moveMamaPig(0);
}

void Controller::game(){
    view.setBackground();

    handleInputs();

    model.computeMamaPigPosition();

    view.rendMamaPig(model.getMamaPigPosX(), model.getMamaPigPosY());
    view.show();
}

void Controller::endGame(){
    view.closeView();
}
