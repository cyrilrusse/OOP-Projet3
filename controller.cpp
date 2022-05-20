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
    manageObjects();
    renderObjects();
    view.show();
}

void Controller::renderObjects(){
    //Rend wolves
    std::vector<Wolf> wolves = model.getWolfArray();
    for(auto &wolf : wolves)
        view.rendWolf(wolf.getStatus(), wolf.getPosx(), wolf.getPosy(), wolf.getStep());

    //Rend mamapig
    view.rendMamaPig(model.getMamaPigPosX(), model.getMamaPigPosY());
    
    //Rend rocks
    std::vector<Rock> rocks = model.getRockArray();
    for(auto &rock : rocks)
        view.rendRock(rock.getPosX(), rock.getPosY());

    //Rend arrow
    if (model.getArrow()->get_meat())
        view.rendMeat(model.getArrow()->getPosX(), model.getArrow()->getPosY(), model.getArrow()->getAngle(), model.getArrow()->getLaunch());
    else
        view.rendArrow(model.getArrow()->getPosX(), model.getArrow()->getPosY(), model.getArrow()->getAngle(), model.getArrow()->getLaunch());

    //Rend nbr of pig eaten
    view.rendNbrPig(model.getNbrPigEaten());
}

void Controller::manageObjects(){
    manageMeat();

    //Compute new mamapig position
    model.computeMamaPigPosition();

    time_since_last_wolf += 1;
    //if 3 sec since last wolf, create a new one
    if(time_since_last_wolf>3*NBR_OF_FPS){
        model.addWolf();
        time_since_last_wolf = 0;
    }
    //Compute new wolves position
    model.computeWolvesPosition();

    //While arrow not launched, set the position of the arrow
    //relatively to mamapig
    if (!model.getArrow()->getLaunch()){
        model.getArrow()->setPosX(model.getMamaPigPosX() - 5);
        model.getArrow()->setPosY(model.getMamaPigPosY() + 30);
    }
    else{
        model.getArrow()->next_position(1./NBR_OF_FPS);
        if (model.getArrow()->canBeSup())
            model.getArrow()->Reload();
    }
    model.getArrow()->setReload(model.getArrow()->getReload()+1);

    //Compute rock position, add rock when necessary and check collisions
    manageRocks();
}

void Controller::closeGame(){
    view.closeView();
}

void Controller::gameOver(){
    //Game over screen
    handleInputs();
    view.rendGameOver();
}

void Controller::manageMeat(){
    if (model.getTimingmeat() >= 300){
        view.rendMeat(400, 170, 0, false);
        model.setMeatAppeared(true);
    }
    if (model.getTimingmeat() < 300 && !model.getMeatAppeared())
        model.setTimingmeat(model.getTimingmeat() + 1);
}

void Controller::manageRocks(){
    model.shotRocks();
    model.changeRocksPosition();
    model.testCollisionPig();
    model.testCollisionWolf();
    model.testArrowMeated();    
    model.removeProjectiles();
}
