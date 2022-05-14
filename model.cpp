#include "model.hpp"

Model::Model(int fps){
    Wolf create_wolf;
    wolf_array.push_back(create_wolf);
    nbr_of_fps = fps;
    timing_meat = 0;
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