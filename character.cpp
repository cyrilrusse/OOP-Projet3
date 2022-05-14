#include "character.hpp"

Character::Character(int x, int y){
    position_x = x;
    position_y = y;
}

Wolf::Wolf():Character(WOLF_INIT_POS){
    switch ((rand()%5)+1){
    case 1:
        falling_pos = WOLF_FALLING_POS1;
        break;
    case 2:
        falling_pos = WOLF_FALLING_POS2;
        break;
    case 3:
        falling_pos = WOLF_FALLING_POS3;
        break;
    case 4:
        falling_pos = WOLF_FALLING_POS4;
        break;
    case 5:
        falling_pos = WOLF_FALLING_POS5;
        break;
    }
    status = WALKING;
}

MamaPig::MamaPig(SDL_Renderer *rend) : Character(MAMAPIG_INIT_POS)
{
    // mama_pig_texture = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/PigMom.bmp"));
    // mama_pig_image_dimension = {5, 5, 20, 10};
    ;
}

SDL_Texture *MamaPig::showMamaPig(SDL_Renderer *rend){
    // mama_pig_texture = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/PigMom.bmp"));
    // mama_pig_image_dimension = {5, 5, 20, 10};
    // SDL_RenderCopy(rend, mama_pig_texture, NULL, &mama_pig_image_dimension);

    SDL_Surface *surf_test = SDL_LoadBMP("../sprites/Arrow.bmp");
    SDL_Texture *text_test = SDL_CreateTextureFromSurface(rend, surf_test);
    // SDL_Rect image_rect = {5, 5, 20, 10};
    // SDL_RenderCopy(rend, text_test, NULL, &image_rect);

    return text_test;
}
