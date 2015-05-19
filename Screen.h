#include <SDL.h>
#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

class Screen {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        int width;
        int height;
        int posX;
        int posY;
        int centerX;
        int centerY;
    public:
        Screen(int,int);
        Screen(int,int,int,int);
        int Xcenter();
        int Ycenter();
        void drawX(int,int);
        void drawX(int,int,int);
        void testScreen();
        void render();
        ~Screen();
};

#endif // SCREEN_H_INCLUDED
