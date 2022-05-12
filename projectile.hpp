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
    public:
        Projectile(int pos_x, int pos_y);
        double calc_acc();
        void next_position();
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