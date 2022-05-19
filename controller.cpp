#include "controller.hpp"

Controller::Controller(){
    ingame = true;
    game_lost = false;
    time_since_last_wolf = 0;
    for(int i=0; i<2; i++)
        keys_pressed[i]= false;
}

void Controller::handleInputs(){
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            ingame = false;
            break;
        }
        switch (event.key.keysym.sym){
            case SDLK_UP:
                if (event.type == SDL_KEYDOWN)
                    keys_pressed[0] = true;
                else if(event.type == SDL_KEYUP)
                    keys_pressed[0] = false;
                break;
            case SDLK_DOWN:
                if (event.type == SDL_KEYDOWN)
                    keys_pressed[1] = true;
                else if (event.type == SDL_KEYUP)
                    keys_pressed[1] = false;
                break;
            case SDLK_SPACE:
                if(model.getArrow()->getReload() >= 30)
                    model.getArrow()->setLaunch(true);
                break;
            default:
                break;
        }
    }
    if(keys_pressed[0]==true && keys_pressed[1]==true)
        model.moveMamaPig(0);
    else if(keys_pressed[0])
        model.moveMamaPig(1);
    else if(keys_pressed[1])
        model.moveMamaPig(-1);
    else
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

    view.rendArrow(model.getArrow()->getPosX(), model.getArrow()->getPosY(), model.getArrow()->getAngle(), model.getArrow()->getLaunch());

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
    if (model.getTimingmeat() >= 270){
        view.rendMeat(400, 170);
        view.setMeatAppeared(true);
    }
    if (model.getTimingmeat() < 270 && !view.getMeatAppeared())
        model.setTimingmeat(model.getTimingmeat() + 1);
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
