#ifndef _MODEL_HPP_
#define _MODEL_HPP_
#include <vector>

#include "character.hpp"
#include "projectile.hpp"

using std::vector;

class Model{
    private:
        MamaPig pig;
        vector <Wolf> wolf_array;
        vector <Rock> rock_array;
        Arrow arrow_array;
    public:
        Model(MamaPig MP, Wolf W, Arrow A);
        MamaPig get_mamapig(){return pig;};
        vector<Wolf> get_wolf_array() { return wolf_array; };
        vector<Rock> get_rock_array() { return rock_array; };
        Arrow get_arrow(){return arrow_array;};
        void mouveMamaPig(bool direction);
};



#endif