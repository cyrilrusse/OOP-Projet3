#include "character.hpp"

Character::Character(int x, int y){
    position_x = x;
    position_y = y;
}

Wolf::Wolf():Character(WOLF_INIT_POS){
    switch ((rand()%5)+1){
    case 1:
        falling_pos = WOLF_FALLING_POS1;
        break;
    case 2:
        falling_pos = WOLF_FALLING_POS2;
        break;
    case 3:
        falling_pos = WOLF_FALLING_POS3;
        break;
    case 4:
        falling_pos = WOLF_FALLING_POS4;
        break;
    case 5:
        falling_pos = WOLF_FALLING_POS5;
        break;
    }
    status = WALKING;
}

MamaPig::MamaPig():Character(MAMAPIG_INIT_POS){};

void MamaPig::computeNewPosition(double time){
    if(direction==UP && position_y > MAMAPIG_BOUND_MIN){
        position_y -= MAMAPIG_MOVEMENT_SPEED*time;
        if(position_y < MAMAPIG_BOUND_MIN)
            position_y = MAMAPIG_BOUND_MIN;
    }
    else if(direction == DOWN && position_y < MAMAPIG_BOUND_MAX){
        position_y += MAMAPIG_MOVEMENT_SPEED*time;
        if(position_y > MAMAPIG_BOUND_MAX)
            position_y = MAMAPIG_BOUND_MAX;
    }
}