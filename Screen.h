#include <SDL.h>
#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

class Screen {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        int width;
        int height;
        int centerX;
        int centerY;
    public:
        Screen(int,int);
        ~Screen();
};

#endif // SCREEN_H_INCLUDED
