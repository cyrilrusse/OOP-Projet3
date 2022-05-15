#ifndef _MODEL_HPP_
#define _MODEL_HPP_
#include <vector>

#include "character.hpp"
#include "projectile.hpp"

using std::vector;

class Model{
    private:
        MamaPig mama_pig;
        vector <Wolf> wolf_array;
        vector <Rock> rock_array;
        Arrow arrow = Arrow(0,0);//à changer
        int nbr_of_fps;
        int timing_meat;
        int nbr_of_little_pig_eaten;
        Uint32 time_last_frame;
    public:
        //Constructor
        Model(int fps);

        //Access
        int getMamaPigPosX(){return mama_pig.getPosx();};
        int getMamaPigPosY() { return mama_pig.getPosy(); };
        vector<Wolf> getWolfArray() {return wolf_array;};
        vector<Rock> getRockArray() {return rock_array;};
        int getTimingmeat(){return timing_meat;};
        Arrow *getArrow(){return &arrow;};
        void moveMamaPig(int direction);
        void computeMamaPigPosition();
        void addWolf();
        void computeWolfsPosition();
        void setTimingmeat(int TM){timing_meat =TM;};
};



#endif