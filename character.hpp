#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP

#include <cstdlib>
#include <SDL2/SDL.h>

#include "projectile.hpp"

//WOLF constant
#define WOLF_INIT_POS 50, 82
#define WOLF_VELOCITY 50, 0
#define WOLF_FALLING_VELOCITY 0, 50
#define WOLD_FREE_FALLING_VELOCITY 0, 100
#define WOLF_FALLING_POS1 75
#define WOLF_FALLING_POS2 125
#define WOLF_FALLING_POS3 150
#define WOLF_FALLING_POS4 200
#define WOLF_FALLING_POS5 250

//MAMAPIG constant
#define MAMAPIG_INIT_POS 400, 240
#define MAMAPIG_BOUND_MIN 170
#define MAMAPIG_BOUND_MAX 405
#define MAMAPIG_MOVEMENT_SPEED 100

enum mama_pig_movement{
    UP,
    NONE,
    DOWN
};

enum wolf_status{
    WALKING,
    BALLON_FALL,
    FREE_FALLING
};

class Character{
protected:
    int position_x, position_y;
public:
    //Constructor
    Character(int x, int y);

    //Access
    int getPosx(){return position_x;}
    int getPosy(){return position_y;}
};

class Wolf : public Character{
private:
    wolf_status status;
    int falling_pos;
public:
    //Constructor
    Wolf();

    //Access
    wolf_status getStatus(){return status;}
};

class MamaPig : public Character{
private:
    Arrow *loaded_arrow;
    mama_pig_movement direction;
public:
    //Constructor
    MamaPig();

    //Setter
    void setDirection(mama_pig_movement new_direction){direction = new_direction;}

    void computeNewPosition(double time);
};

#endif
