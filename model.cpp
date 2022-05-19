#include "model.hpp"

Model::Model(int fps){
    Wolf create_wolf;
    wolf_array.push_back(create_wolf);
    nbr_of_fps = fps;
    timing_meat = 0;
    nbr_of_little_pig_eaten = 0;
    time_last_frame = SDL_GetTicks();
    has_lost = false;
}

void Model::moveMamaPig(int direction){
    if(direction==1)
        mama_pig.setDirection(UP);
    else if(direction==-1)
        mama_pig.setDirection(DOWN);
    else 
        mama_pig.setDirection(NONE);
}

void Model::computeMamaPigPosition(){
    mama_pig.computeNewPosition(1./nbr_of_fps);
}

void Model::addWolf(){
    wolf_array.push_back(Wolf());
}

void Model::changeRocksPosition(){
    for(auto &rock : rock_array)
        rock.next_position();

    
}

void Model::removeProjectiles(){
    for(int i=rock_array.size()-1; i>=0; i--){
        if(rock_array[i].canBeSup())
            rock_array.erase(rock_array.begin()+i);
    }
}

void Model::computeWolfsPosition(){
    vector<int> wolf_to_remove;
    int i = 0;
    for(auto &wolf : wolf_array){
        wolf.computeNewPosition(1./nbr_of_fps);
        if(wolf.getStatus()==REACHED_HOUSE){
            nbr_of_little_pig_eaten++;
            wolf_to_remove.push_back(i);
        }
        else if(wolf.getStatus()==DISAPEAR)
            wolf_to_remove.push_back(i);
        i++;
    }
    for(i = wolf_to_remove.size(); i>0; i--)
        wolf_array.erase(wolf_array.begin()+wolf_to_remove[i-1]);
    if(nbr_of_little_pig_eaten>=5)
        has_lost = true;
}

void Model::shotRocks(){
    for (auto &wolf : wolf_array){
        if (wolf.getPosy() >= 230 && wolf.getReload() >= 90 && wolf.getStatus()==BALLON_FALL){
            addRock(Rock(wolf.getPosx() + 30, wolf.getPosy()));
            wolf.setReload(0);
        }
        else
            wolf.setReload(wolf.getReload() + 1);
    }
    // time_last_frame = SDL_GetTicks();
}

void Model::testCollisionPig()
{
    for (auto &rock : rock_array){
        if (rock.getPosX() < mama_pig.getPosx() + 30 &&
            rock.getPosX() + rock.getSizex() > mama_pig.getPosx() &&
            rock.getPosY() < mama_pig.getPosy() + 50 &&
            rock.getPosY() + rock.getSizey() > mama_pig.getPosy())
            has_lost = true;
    }
}

void Model::testCollisionWolf(){
    for (auto &wolf : wolf_array)
    {
        if (wolf.getPosx() + 15 < arrow.getPosX() + arrow.getSizex() &&
            wolf.getPosx() + 30 > arrow.getPosX() &&
            wolf.getPosy() - 17 < arrow.getPosY() + arrow.getSizey()&&
            wolf.getPosy() > arrow.getPosY())
            wolf.setStatus(FREE_FALLING);
        else if (wolf.getPosx() < arrow.getPosX() + arrow.getSizex() &&
                 wolf.getPosx() + 30 > arrow.getPosX() &&
                 wolf.getPosy() < arrow.getPosY() + arrow.getSizey() &&
                 wolf.getPosy() + 35 > arrow.getPosY()){ 
                if(arrow.get_meat())
                    wolf.setStatus(FREE_FALLING);
                else
                    arrow.Reload();
                }
    }
}