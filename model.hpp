#ifndef _MODEL_HPP_
#define _MODEL_HPP_
#include <vector>

#include "character.hpp"
#include "projectile.hpp"

#define POSITION_WOLF_START_SHOOTING 230
#define TIME_WOLF_RELOAD 90

using std::vector;

class Model{
    private:
        MamaPig mama_pig;
        vector <Wolf> wolf_array;
        vector <Rock> rock_array;
        Arrow arrow = Arrow(0,0);//à changer
        int nbr_of_fps, timing_meat, nbr_of_little_pig_eaten;
        bool has_lost, meat_appeared;
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
        int getNbrPigEaten(){return nbr_of_little_pig_eaten;};
        bool getMeatAppeared() { return meat_appeared;};
        bool hasLost(){return has_lost;};

        //Setters
        void setTimingmeat(int TM){timing_meat =TM;};
        void setMeatAppeared(bool MA) { meat_appeared = MA;};

        void addRock(Rock R){rock_array.push_back(R);};
        void addWolf();
        void shotRocks();
        void removeProjectiles();
        
        void changeRocksPosition();
        void moveMamaPig(int direction);
        void computeMamaPigPosition();
        void computeWolvesPosition();

        void testCollisionPig();
        void testCollisionWolf();
        void testArrowMeated();
};



#endif