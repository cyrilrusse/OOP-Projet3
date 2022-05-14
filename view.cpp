#include "view.hpp"

#include <iostream>

View::View(int fps){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        printf("error initializing SDL: %s\n", SDL_GetError());

    window = SDL_CreateWindow("Pooyan",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WEIGHT, HEIGHT, 0);
    rend = SDL_CreateRenderer(window, -1, 0);

    ledge.h = 70;
    ledge.w = 350;
    ledge.x = 0;
    ledge.y = 100;

    column.h = 310;
    column.w = 70;
    column.x = 0;
    column.y = 170;

    ground.h = 100;
    ground.w = 550;
    ground.x = 0;
    ground.y = 480;

    house.h = 75;
    house.w = 100;
    house.x = 450;
    house.y = 405;

    nbr_of_fps = fps;

    //texture loading
    text_wolf_walking1 = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/Wolf_WalkingLeft_Step1.bmp"));
    text_wolf_walking2 = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/Wolf_WalkingLeft_Step2.bmp"));
    text_wolf_walking1_balloon = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/Wolf_WalkingLeft_Balloon_Step1.bmp"));
    text_wolf_walking2_balloon = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/Wolf_WalkingLeft_Balloon_Step2.bmp"));
    text_wolf_falling = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/Wolf_Falling_Balloon.bmp"));
    text_wolf_free_falling = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/Wolf_Free_Falling.bmp"));
    text_mama_pig = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/PigMom.bmp"));
    text_arrow = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/Arrow.bmp"));
    text_meaty_arrow = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/Meat.bmp"));
    text_balloon = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/Balloon.bmp"));
    text_rock = SDL_CreateTextureFromSurface(rend, SDL_LoadBMP("../sprites/Rock.bmp"));
}

void View::setBackground(){
    SDL_SetRenderDrawColor(rend, BLUE, 255);
    SDL_RenderClear(rend);

    SDL_SetRenderDrawColor(rend, GREEN, 255);
    SDL_RenderFillRect(rend, &ledge);

    SDL_SetRenderDrawColor(rend, BROWN, 255);
    SDL_RenderFillRect(rend, &column);

    SDL_SetRenderDrawColor(rend, GROUNDBROWN, 255);
    SDL_RenderFillRect(rend, &ground);

    SDL_SetRenderDrawColor(rend, GREY, 255);
    SDL_RenderFillRect(rend, &house);
}

void View::show(){
    SDL_Rect rect_pour_image = {5, 5, MAMAPIG_DIMENSIONS};
    SDL_RenderCopy(rend, text_mama_pig, NULL, &rect_pour_image);

    SDL_RenderPresent(rend);
    SDL_Delay(1000 / nbr_of_fps);
}

void View::closeView(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}