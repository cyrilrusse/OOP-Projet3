#include <SDL2/SDL.h>

class Controller
{
private:
    SDL_Event event;
    bool ingame;
public:
    Controller();

    //Access
    bool inGame(){return ingame;}
    void handleInputs();
    
};