#include "Screen.h"
#include <SDL.h>


Screen::Screen(int w, int h) : width(w), height(h), centerX(w/2), centerY(h/2) {
    this->window = SDL_CreateWindow(    "SDL Graphics",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        w,
                                        h,
                                        SDL_WINDOW_HIDDEN
    );

    this->renderer = SDL_CreateRenderer(    window,
                                            -1,
                                            SDL_RENDERER_ACCELERATED
    );

    SDL_ShowWindow(this->window);

    SDL_SetRenderDrawColor(this->renderer,255,255,255,255);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
}
Screen::Screen(int w, int h, int x, int y) : width(w), height(h), centerX(w/2), centerY(h/2) {
    this->window = SDL_CreateWindow(    "SDL Graphics",
                                        x,
                                        y,
                                        w,
                                        h,
                                        SDL_WINDOW_HIDDEN
    );

    this->renderer = SDL_CreateRenderer(    window,
                                            -1,
                                            SDL_RENDERER_ACCELERATED
    );

    SDL_ShowWindow(this->window);

    SDL_SetRenderDrawColor(this->renderer,255,255,255,255);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
}
int Screen::Xcenter() { return this->centerX; }
int Screen::Ycenter() { return this->centerY; }
void Screen::drawX(int x,int y) {
    int l = 3;
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderDrawLine(renderer, x - l, y - l, x + l,y + l);
    SDL_RenderDrawLine(renderer, x - l, y + l, x + l,y - l);
}
void Screen::drawX(int x,int y, int l) {
    SDL_RenderDrawLine(renderer, x - l, y - l, x + l,y + l);
    SDL_RenderDrawLine(renderer, x - l, y + l, x + l,y - l);
}
void Screen::render() {
    SDL_RenderPresent(this->renderer);
}
void Screen::testScreen() {
    int n1 = 1; ///x
    int n2 = 1; ///y
    bool b1 = true; ///x
    bool b2 = true; ///y

    while(event.window.event != SDL_WINDOWEVENT_CLOSE ) {
        SDL_SetRenderDrawColor(renderer,0,0,0,255);

        if(n1 < this->width && b1 == true)
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
        if(n2 < this->height && b2 == true)
            n2++;
        else if(b2 == true)
            b2 = false;

        SDL_RenderDrawPoint(this->renderer,n1,n2);
        SDL_RenderPresent(this->renderer);
        SDL_PollEvent(&event);
    }
}
Screen::~Screen() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}

