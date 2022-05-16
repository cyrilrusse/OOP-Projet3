#include "controller.hpp"

Controller::Controller(){
    ingame = true;
    game_lost = false;
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
                if(model.getArrow()->getReload() >= 30)
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

    manageTiming();
    manageObjects();
    renderObjects();
    manageRocks();

    view.rendArrow(model.getArrow()->getPosX(), model.getArrow()->getPosY(), model.getArrow()->getAngle());

    view.rendNbrPig(model.getNbrPigEaten());

    view.show();
}

void Controller::renderObjects(){
    std::vector<Wolf> wolfs = model.getWolfArray();
    for(auto &wolf : wolfs)
        view.rendWolf(wolf.getStatus(), wolf.getPosx(), wolf.getPosy(), wolf.getStep());

    view.rendMamaPig(model.getMamaPigPosX(), model.getMamaPigPosY());
    std::vector<Rock> rocks = model.getRockArray();
    for(auto &rock : rocks){ 
        view.rendRock(rock.getPosX(), rock.getPosY());
    }
}

void Controller::manageObjects(){
    time_since_last_wolf += 1;
    if(time_since_last_wolf>3*NBR_OF_FPS){
        model.addWolf();
        time_since_last_wolf = 0;
    }
    model.computeWolfsPosition();
    if (!model.getArrow()->getLaunch())
    {
        model.getArrow()->setPosX(model.getMamaPigPosX() - 5);
        model.getArrow()->setPosY(model.getMamaPigPosY() + 30);
    }
    else
    {
        model.getArrow()->next_position();
        if (model.getArrow()->canBeSup()){
            model.getArrow()->Reload();
        }
    }
    model.getArrow()->setReload(model.getArrow()->getReload()+1);
}

void Controller::closeGame(){
    view.closeView();
}

void Controller::gameOver(){
    handleInputs();
    view.rendGameOver();
}

void Controller::manageTiming(){
    if (model.getTimingmeat() >= 270)
    {
        view.rendMeat(400, 170);
        view.setMeatAppeared(true);
    }
    if (model.getTimingmeat() < 270 && !view.getMeatAppeared())
    {
        model.setTimingmeat(model.getTimingmeat() + 1);
    }
}

void Controller::manageRocks(){
    std::vector<Wolf> wolfs = model.getWolfArray();
    for(auto &wolf : wolfs){
        if(wolf.getPosy() == 230 || wolf.getReload()==90){
            model.addRock(Rock(wolf.getPosx()+30,wolf.getPosy()));
            wolf.setReload(0);
        }
        else
            wolf.setReload(wolf.getReload()+1);
    }
    model.changeRocksPosition();
}
