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
        void next_position();


};

class Arrow: public Projectile{
    public:
        Arrow(int pos_x, int pos_y);

};

class Rock: public Projectile{
    public:
        Rock(int pos_x, int pos_y);

};