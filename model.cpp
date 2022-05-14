#include <vector>
#include "model.hpp"
#include "character.hpp"
#include "projectile.hpp"

Model::Model(MamaPig MP, Wolf W, Arrow A){
    pig = MP;
    wolf_array.push_back(W);
    arrow_array = A;
}