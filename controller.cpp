#include "controller.hpp"

Controller::Controller(){
    ingame = true;
    time_since_last_wolf = 0;
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
                model.getArrow()->setLaunch(true);
                break;
                
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
    if(model.getTimingmeat() >= 270){ 
        view.rendMeat(400, 170);
        view.setMeatAppeared(true);
        
    }
    if(model.getTimingmeat() < 270 && !view.getMeatAppeared()){
        model.setTimingmeat(model.getTimingmeat()+1);
    }
    manageObjects();
    renderObjects();

    if(!model.getArrow()->getLaunch()){ 
        model.getArrow()->setPosX(model.getMamaPigPosX() - 5);
        model.getArrow()->setPosY(model.getMamaPigPosY() +30);
    }
    else{
        model.getArrow()->next_position();
        std::cout << model.getArrow()->getVelocityX() << " " << model.getArrow()->getVelocityY() << std::endl;
    }

    view.rendArrow(model.getArrow()->getPosX(), model.getArrow()->getPosY());

    view.rendMamaPig(model.getMamaPigPosX(), model.getMamaPigPosY());
    view.show();
}

void Controller::renderObjects(){
    std::vector<Wolf> wolfs = model.getWolfArray();
    for(auto &wolf : wolfs)
        view.rendWolf(wolf.getStatus(), wolf.getPosx(), wolf.getPosy(), wolf.getStep());

    view.rendMamaPig(model.getMamaPigPosX(), model.getMamaPigPosY());
}

void Controller::manageObjects(){
    time_since_last_wolf += 1;
    if(time_since_last_wolf>3*NBR_OF_FPS){
        model.addWolf();
        time_since_last_wolf = 0;
    }
    model.computeWolfsPosition();
}

void Controller::endGame(){
    view.closeView();
}
