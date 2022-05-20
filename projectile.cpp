#include "projectile.hpp"

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

void Projectile::next_position(double time){
    angle = atan(velocity_y/velocity_x);
    double dragForce = calcDragForce();
    double accX = dragForce*cos(angle+M_PI)/masse;
    double accY = (dragForce*sin(angle + M_PI) + GRAVITY*masse)/masse;
    velocity_y += accY*time/*30*/ ;
    velocity_x -= accX*time;
    position_x += velocity_x*time;
    position_y += velocity_y*time;
}

bool Projectile::canBeSup(){
    if(position_y < BOUND_Y||(position_x < BOUND_X_MAX && position_x > BOUND_X_MIN))
        return false;
    return true;
}
void Projectile::Reload(){
    angle = (180 + ARROW_SHOOTING_ANGLE) * M_PI / 180;
    velocity_x = ARROW_SHOOTING_POWER * cos(angle);
    velocity_y = ARROW_SHOOTING_POWER * sin(angle);
    launch = false;
}
void Arrow::Reload(){
    Projectile::Reload();
    meat = false;
}

Arrow::Arrow(int pos_x, int pos_y):Projectile(pos_x,pos_y){
    meat = false;
    size_x = ARROW_SIZE_X;
    size_y = ARROW_SIZE_Y;
    angle = (180 + ARROW_SHOOTING_ANGLE) * M_PI / 180;
    masse = ARROW_MASSE;
    cross_area = ARROW_CROSS_AREA;
    velocity_x = ARROW_SHOOTING_POWER * cos(angle);
    velocity_y = ARROW_SHOOTING_POWER * sin(angle);
}

void Arrow::arrow_meat(){
    meat = true;
    masse = MEATY_ARROW_MASSE;
    cross_area = MEATY_ARROW_CROSS_AREA;
    angle = (180 + MEATY_ARROW_SHOOTING_ANGLE) * M_PI / 180;
    velocity_x = MEATY_ARROW_SHOOTING_POWER * cos(angle);
    velocity_y = MEATY_ARROW_SHOOTING_POWER * sin(angle);
    launch = false;
}


Rock::Rock(int pos_x, int pos_y) : Projectile(pos_x, pos_y){
    size_x = ROCK_SIZE_X;
    size_y = ROCK_SIZE_Y;
    masse = ROCK_MASSE;
    angle = -1*ROCK_ANGLE*M_PI / 180;
    cross_area = ROCK_CROSS_AREA;
    velocity_x = ROCK_SHOOTING_POWER * cos(angle );
    velocity_y = ROCK_SHOOTING_POWER * sin(angle );
}
