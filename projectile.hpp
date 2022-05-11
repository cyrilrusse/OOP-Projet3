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
}

class Arrow: public Projectile{

}

class Rock: public Projectile{

}