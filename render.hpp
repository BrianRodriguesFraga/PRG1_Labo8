#ifndef render_hpp
#define render_hpp

#include <SDL.h>
#undef main

#include "types.hpp"

class Render
{
    public:
        Render(dim_t wsize, int scale);

        ~Render();

        void draw_board();

        void update();

        SDL_Renderer* getRenderer();

        SDL_Window* getWindow();

    private:
        SDL_Window* window;

        SDL_Renderer* renderer;

};

#endif