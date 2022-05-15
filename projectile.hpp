#ifndef _PROJECTILE_HPP_
#define _PROJECTILE_HPP_
#include <cmath>
#include <iostream>

class Projectile{
    protected:
        int position_x;
        int position_y;
        int masse;
        int size_x;
        int size_y;
        double velocity_x;
        double velocity_y;
        double angle;
        int cross_area;
        bool launch; 
    public:
        Projectile(int pos_x, int pos_y);
        double calc_acc();
        void next_position();
        int getPosX(){return position_x;};
        int getPosY(){return position_y;};
        void setPosX(int PX){position_x = PX;};
        void setPosY(int PY){position_y = PY;};
        double getVelocityY(){return velocity_y;};
        int getSizex(){return size_x;};
        int getSizey(){return size_y;};
        bool getLaunch(){return launch;};
        void setLaunch(bool L){launch = L;};
};

class Arrow: public Projectile{
    private:
        bool meat;
    public:
        Arrow(int pos_x, int pos_y);
        void arrow_meat();
        bool get_meat(){return meat;};
};

class Rock: public Projectile{
    public:
        Rock(int pos_x, int pos_y);

};

#endif