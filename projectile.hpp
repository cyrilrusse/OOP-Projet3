#ifndef _PROJECTILE_HPP_
#define _PROJECTILE_HPP_
#include <cmath>
#include <iostream>

#define AIR_DENSITY 1
#define DRAG_COEF 0.001
#define GRAVITY 500

//Arrow Constants
#define ARROW_MASSE 5
#define ARROW_SHOOTING_POWER 500
#define ARROW_CROSS_AREA 1
#define ARROW_SHOOTING_ANGLE 5
#define ARROW_SIZE_X 20
#define ARROW_SIZE_Y 10
#define BOUND_X_MIN 0
#define BOUND_X_MAX 550
#define BOUND_Y 480

//Meaty Arrow Constants
#define MEATY_ARROW_MASSE 30
#define MEATY_ARROW_CROSS_AREA 10
#define MEATY_ARROW_SHOOTING_ANGLE 5
#define MEATY_ARROW_SHOOTING_POWER 500

//Rock Constants
#define ROCK_SIZE_X 15
#define ROCK_SIZE_Y 15
#define ROCK_MASSE 30
#define ROCK_ANGLE 50
#define ROCK_CROSS_AREA 1
#define ROCK_SHOOTING_POWER 250

class Projectile{
protected:
    int position_x, position_y, size_x, size_y;
    int masse, cross_area;
    bool launch;
    double velocity_x, velocity_y, angle;
public:
    //Constructor
    Projectile(int pos_x, int pos_y);

    //Access
    int getPosX(){return position_x;};
    int getPosY(){return position_y;};
    double getVelocityY(){return velocity_y;};
    double getVelocityX(){return velocity_x; };
    int getSizex(){return size_x;};
    int getSizey(){return size_y;};
    bool getLaunch(){return launch;};
    void setLaunch(bool L){launch = L;};
    double getAngle(){return angle;};

    //Setters
    void setPosX(int PX){position_x = PX;};
    void setPosY(int PY){position_y = PY;};
    
    double calcDragForce();
    void next_position(double time);
    bool canBeSup();
    void Reload();
};

class Arrow: public Projectile{
private:
    bool meat;
    int reload = 30;
public:
    //Constructor
    Arrow(int pos_x, int pos_y);

    //Access
    int getReload(){return reload;};
    bool get_meat(){return meat;};

    //Setters
    void setReload(int R){reload = R;};
    
    void arrow_meat();
    void Reload();
};

class Rock: public Projectile{
    public:
        Rock(int pos_x, int pos_y);

};

#endif