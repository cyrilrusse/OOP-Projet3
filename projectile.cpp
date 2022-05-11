#include "projectile.hpp"
#include "math.h"

Arrow::Arrow(int pos_x, int pos_y){
    position_x = pos_x;
    position_y = pos_y;
    size_x = 20;
    size_y = 10;
    velocity_x = 250*tan(angle);
    velocity_y = 250*sin(angle);
    masse = 5;
    angle = 5;
    cross_area = 1;
}

Rock::Rock(int pos_x, int pos_y){
    position_x = pos_x;
    position_y = pos_y;
    size_x = 15;
    size_y = 15;
    masse = 30;
    angle = 50;
    cross_area = 1;
    velocity_x = 250 * tan(angle);
    velocity_y = 250 * sin(angle);
}