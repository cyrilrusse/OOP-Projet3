#include "character.hpp"

Character::Character(int x, int y){
    position_x = x;
    position_y = y;
}

//Wolf definitions
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

void Wolf::computeNewPosition(double time){
    if(status == WALKING){
        ++step %= 2;
        position_x += WOLF_VELOCITY * time;
        if(position_x >= falling_pos){
            position_x = falling_pos;
            status = BALLON_FALL;
        }
        return;
    }
    if(status == BALLON_FALL){
        position_y += WOLF_FALLING_VELOCITY * time;
        if(position_y >= WOLF_GROUND_POSITION){
            position_y = WOLF_GROUND_POSITION;
            status = WALKING_WITHOUT_BALLOON;
        }
        return;
    }
    if(status == WALKING_WITHOUT_BALLOON){
        ++step %= 2;
        position_x += WOLF_VELOCITY * time;
        if(position_x >= WOLF_HOUSE_REACHED)
            status = REACHED_HOUSE;
        return;
    }
    if(status == FREE_FALLING){
        position_y += WOLD_FREE_FALLING_VELOCITY * time;
        if (position_y >= WOLF_GROUND_POSITION){
            position_y = WOLF_GROUND_POSITION;
            status = DISAPEAR;
        }
        return;
    }

}


//MamaPig definitions
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

