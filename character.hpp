#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP

enum wolf_status
{
    WALKING,
    BALLON_FALL,
    FREE_FALLING
};

class Character
{
private:
    int x, y;
    //Projectiles?
public:
    Character();
    ~Character();
};

class Wolf : public Character
{
private:
    wolf_status status;

public:
    //Access
    wolf_status getStatus(){return status;}
};

class MamaPig : public Character
{
private:

public:
};

#endif
