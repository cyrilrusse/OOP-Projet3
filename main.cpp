#include <SDL2/SDL.h>
#include <stdlib.h>


#define HEIGHT 580
#define WEIGHT 550
#define BLUE 0, 0, 255
#define GREEN 0, 255, 0
#define BROWN 128, 96, 60
#define GROUNDBROWN 128, 96, 20
#define GREY 220, 220, 220

static void setBackground(SDL_Renderer *rend){
    SDL_Rect ledge;
    ledge.h = 70;
    ledge.w = 350;
    ledge.x = 0;
    ledge.y = 100;

    SDL_Rect column;
    column.h = 310;
    column.w = 70;
    column.x = 0;
    column.y = 170;

    SDL_Rect ground;
    ground.h = 100;
    ground.w = 550;
    ground.x = 0;
    ground.y = 480;

    SDL_Rect house;
    house.h = 75;
    house.w = 100;
    house.x = 450;
    house.y = 405;

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

int main(){
    bool ingame = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        printf("error initializing SDL: %s\n", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow("Pooyan",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WEIGHT, HEIGHT, 0);

    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, 0);
    // SDL_Surface *surface = SDL_GetWindowSurface(window);
    // SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, BLUE));
    // SDL_Texture *background = SDL_CreateTextureFromSurface(rend, surface);
    // SDL_QueryTexture(background, NULL, NULL, &dest.w, &dest.h);

    while (ingame){

        SDL_Event event;

        setBackground(rend);

        while (SDL_PollEvent(&event)){
            switch (event.type)
            {
            case SDL_QUIT:
                ingame = false;
                break;
            
            default:
                break;
            }
        }

        SDL_RenderPresent(rend);

        // 60 frame per second
        SDL_Delay(1000 / 60);
    }


    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
    
}