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
    public:
        //Constructor
        Model(int fps);

        //Access
        int getMamaPigPosX(){return mama_pig.getPosx();};
        int getMamaPigPosY() { return mama_pig.getPosy(); };
        vector<Wolf> getWolfArray() {return wolf_array;};
        vector<Rock> getRockArray() {return rock_array;};
        Arrow getArrow(){return arrow;};
        int getTimingmeat(){return timing_meat;};

        void moveMamaPig(int direction);
        void computeMamaPigPosition();
        void addWolf();
        void setTimingmeat(int TM){timing_meat =TM;};
};



#endif