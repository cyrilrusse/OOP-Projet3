#include "model.hpp"

Model::Model(int fps){
    Wolf create_wolf;
    wolf_array.push_back(create_wolf);
    nbr_of_fps = fps;
    timing_meat = 0;
    nbr_of_little_pig_eaten = 0;
    has_lost = false;
    meat_appeared = false;
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
        rock.next_position(1./nbr_of_fps);
}

void Model::removeProjectiles(){
    for(int i=rock_array.size()-1; i>=0; i--){
        if(rock_array[i].canBeSup())
            rock_array.erase(rock_array.begin()+i);
    }
}

void Model::computeWolvesPosition(){
    vector<int> wolf_to_remove;
    int i = 0;
    for(auto &wolf : wolf_array){
        wolf.computeNewPosition(1./nbr_of_fps);
        //Check wolf status, add index in array containing 
        //indexes of wolves to remove and increment nbr of pig
        //eaten if it has reached the mamapig house
        if(wolf.getStatus()==REACHED_HOUSE){
            nbr_of_little_pig_eaten++;
            wolf_to_remove.push_back(i);
        }
        else if(wolf.getStatus()==DISAPEAR)
            wolf_to_remove.push_back(i);
        i++;
    }
    //Browse index array of wolves to remove in reverse
    //and erase for each index stored the corresponding
    //wolf in the wolf_array
    //We do it reverse to make sure that if 2 wolves
    //must be removed at the same time, we would not 
    //move the rest of the array by removing the first wolf
    //and then try to remove the second one at the stored index
    //that would not be the good one anymore
    for(i = wolf_to_remove.size(); i>0; i--)
        wolf_array.erase(wolf_array.begin()+wolf_to_remove[i-1]);
    
    //Set the status of the game to lost if all pig eaten
    if(nbr_of_little_pig_eaten>=5)
        has_lost = true;
}

void Model::shotRocks(){
    for (auto &wolf : wolf_array){
        if (wolf.getPosy() >= POSITION_WOLF_START_SHOOTING && wolf.getReload() >= TIME_WOLF_RELOAD && wolf.getStatus()==BALLON_FALL){
            addRock(Rock(wolf.getPosx() + 30, wolf.getPosy()));
            wolf.setReload(0);
        }
        else
            wolf.setReload(wolf.getReload() + 1);
    }
}

void Model::testCollisionPig(){
    for (auto &rock : rock_array){
        if (rock.getPosX() < mama_pig.getPosx() + 30 &&
            rock.getPosX() + rock.getSizex() > mama_pig.getPosx() &&
            rock.getPosY() < mama_pig.getPosy() + 50 &&
            rock.getPosY() + rock.getSizey() > mama_pig.getPosy())
            has_lost = true;
    }
}

void Model::testCollisionWolf(){
    for (auto &wolf : wolf_array){
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

void Model::testArrowMeated(){
    if(mama_pig.getPosy()<175 && meat_appeared){ 
        arrow.arrow_meat();
        timing_meat = 0;
        meat_appeared = false;
    }
}