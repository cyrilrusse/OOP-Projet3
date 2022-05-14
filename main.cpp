#include <SDL2/SDL.h>
#include <stdlib.h>

#include "view.hpp"
#include "controller.hpp"
#include "projectile.hpp"
#include "model.hpp"

#define NBR_OF_FPS 30

int main(){
    View view(NBR_OF_FPS);
    Controller controller;
    
    while (controller.inGame()){
        view.setBackground();

        controller.handleInputs();

        view.show();
    }

    view.closeView();


    return 0;
}