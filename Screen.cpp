#include "Screen.h"
#include <SDL.h>


Screen::Screen(int w, int h) {
    this->width = w;
    this->height = h;
    this->centerX = width / 2;
    this->centerY = height / 2;

    this->window = SDL_CreateWindow(  "SDL Graphics",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                width,
                                height,
                                SDL_WINDOW_HIDDEN
    );

    this->renderer = SDL_CreateRenderer(  window,
                                    -1,
                                    SDL_RENDERER_ACCELERATED
    );
}

