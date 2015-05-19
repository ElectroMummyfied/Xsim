#include <iostream>
#include <SDL.h>
#include "Trinion.h"
#include "Xnum.h"

using namespace std;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

void drawX(SDL_Renderer *, int,int);

int main(int argc,char *argv[]){

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /**
    Xnum<double> num1(3,4);
    Xnum<double> num2(-4,3);
    Xnum<double> num3(0,1);
    */
    ///print(num1 * num2);

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(  "SDL Graphics",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                WINDOW_WIDTH,
                                WINDOW_HEIGHT,
                                SDL_WINDOW_HIDDEN
    );

    renderer = SDL_CreateRenderer(  window,
                                    -1,
                                    SDL_RENDERER_ACCELERATED
    );

    SDL_ShowWindow(window);

    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    drawX(renderer,WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    SDL_RenderPresent(renderer);

    int n1 = 1; ///x
    int n2 = 1; ///y
    bool b1 = true; ///x
    bool b2 = true; ///y

    while(!SDL_QuitRequested()){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);

        if(n1 < WINDOW_WIDTH && b1 == true)
            n1++;
        else if(b1 == true)
            b1 = false;
        if(n1 > 0 && b1 == false)
            n1--;
        else if(b1 == false)
            b1 = true;

        if(n2 > 0 && b2 == false)
            n2--;
        else if(b2 == false)
            b2 = true;
        if(n2 < WINDOW_HEIGHT && b2 == true)
            n2++;
        else if(b2 == true)
            b2 = false;

        SDL_RenderPresent(renderer);
        cout << "n1 = " << n1 << endl;
        cout << "n2 = " << n2 << endl;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void drawX(SDL_Renderer *renderer,int x,int y) {
    int l = 3;
    SDL_RenderDrawLine(renderer, x - l, y - l, x + l,y + l);
    SDL_RenderDrawLine(renderer, x - l, y + l, x + l,y - l);
}
