#include "model.hpp"

Model::Model(){
    Wolf create_wolf;
    wolf_array.push_back(create_wolf);
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
    mama_pig.computeNewPosition(1./30);
}