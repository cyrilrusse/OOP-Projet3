#include <SDL2/SDL.h>

#define HEIGHT 580
#define WEIGHT 550
#define BLUE 0, 0, 255
#define GREEN 0, 255, 0
#define BROWN 128, 96, 60
#define GROUNDBROWN 128, 96, 20
#define GREY 220, 220, 220

class View
{
private:
    SDL_Window* window;
    SDL_Renderer *rend;
    SDL_Rect ledge, column, ground, house;

public:
    View();
    void setBackground();
    void show();
    void closeView();
};
