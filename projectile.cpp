#include "projectile.hpp"
#define AIR_DENSITY 1
#define DRAG_COEF 0.001

// void Projectile::next_position(){
    
// }
Projectile::Projectile(int pos_x, int pos_y){
    position_x = pos_x;
    position_y = pos_y;
    launch = false;
}

double Projectile::calcDragForce(){
    double norme_velocity = sqrt(velocity_x*velocity_x+velocity_y*velocity_y);
    double drag_force = (1./2)*AIR_DENSITY*cross_area*DRAG_COEF*norme_velocity*norme_velocity;
    return drag_force;
}

void Projectile::next_position(){
    angle = atan(velocity_y/velocity_x);
    double dragForce = calcDragForce();
    double accX = dragForce*cos(angle+M_PI)/masse;
    double accY = (dragForce*sin(angle + M_PI) + 500*masse)/masse;
    velocity_y += accY/30;
    velocity_x -= accX/30;
    position_x += velocity_x/30;
    position_y += velocity_y/30;
}



Arrow::Arrow(int pos_x, int pos_y):Projectile(pos_x,pos_y){
    meat = false;
    size_x = 20;
    size_y = 10;
    angle = 185;
    masse = 5;
    cross_area = 1;
    velocity_x = 500 * cos(angle * M_PI / 180);
    velocity_y = 500 * sin(angle * M_PI / 180);
}

void Arrow::arrow_meat(){
    meat = true;
    masse = 30;
    cross_area = 10;
}

Rock::Rock(int pos_x, int pos_y) : Projectile(pos_x, pos_y)
{
    size_x = 15;
    size_y = 15;
    masse = 30;
    angle = -50;
    cross_area = 1;
    velocity_x = 250 * cos(angle * M_PI / 180);
    velocity_y = 250 * sin(angle * M_PI / 180);
}
