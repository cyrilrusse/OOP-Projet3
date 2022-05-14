#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP

#include <cstdlib>
#include <SDL2/SDL.h>

#include "projectile.hpp"

#define WOLF_INIT_POS 50, 82
#define WOLF_VELOCITY 50, 0
#define WOLF_FALLING_VELOCITY 0, 50
#define WOLD_FREE_FALLING_VELOCITY 0, 100
#define WOLF_FALLING_POS1 75
#define WOLF_FALLING_POS2 125
#define WOLF_FALLING_POS3 150
#define WOLF_FALLING_POS4 200
#define WOLF_FALLING_POS5 250

#define MAMAPIG_INIT_POS 400, 240
#define MAMAPIG_BOUND_MIN 170
#define MAMAPIG_BOUND_MAX 405



enum wolf_status{
    WALKING,
    BALLON_FALL,
    FREE_FALLING
};

class Character{
private:
    int position_x, position_y;
public:
    Character(int x, int y);
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
    SDL_Texture *mama_pig_texture;
    SDL_Rect mama_pig_image_dimension;
public:
    //Constructor
    MamaPig(SDL_Renderer *rend);

    //Access
    
    SDL_Texture *showMamaPig(SDL_Renderer *rend);
};

#endif
