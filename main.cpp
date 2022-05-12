#include <SDL2/SDL.h>
#include <stdlib.h>

#include "view.hpp"
#include "controller.hpp"
#include "projectile.hpp"

int main(){
    View view;
    Controller controller;
    
    while (controller.inGame()){
        view.setBackground();

        controller.handleInputs();

        view.show();
    }

    view.closeView();


    return 0;
}