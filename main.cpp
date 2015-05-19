#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include "Trinion.h"
#include "Xnum.h"

using namespace std;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;


int main(int argc,char *argv[]){
    SDL_Init(SDL_INIT_VIDEO);

    Screen main_screen(WINDOW_WIDTH,WINDOW_HEIGHT);
    main_screen.testScreen();
    
    SDL_Delay(1000);
    SDL_Quit();

    return 0;
}

