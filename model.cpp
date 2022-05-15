#include "model.hpp"

Model::Model(int fps){
    Wolf create_wolf;
    wolf_array.push_back(create_wolf);
    nbr_of_fps = fps;
    timing_meat = 0;
    nbr_of_little_pig_eaten = 0;
    time_last_frame = SDL_GetTicks();
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

void Model::computeWolfsPosition(){
    vector<int> wolf_to_remove;
    int i = 0;
    Uint32 new_time = SDL_GetTicks();
    Uint32 delta_t = new_time - time_last_frame;
    std::cout << "delta t: " << delta_t << std::endl;
    for(auto &wolf : wolf_array){
        wolf.computeNewPosition(delta_t/1000.);
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
    time_last_frame = SDL_GetTicks();
}