/*---------------------------------------------------------------------------
  Fichier     : render.hpp
  Nom du labo : TP8 - Snake
  Auteur(s)   : Ernst Laurent - Rodrigues Fraga Brian
  Date        : 20.01.2022
  But         : Nous souhaitons simuler des serpents allant chercher des pommes. Lors de leurs
                déplacements, les serpents s’attaquent entre eux.
                La partie se termine lorsque qu’un seul serpent est en jeu.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.3.0
  IDE         : Clion 2022.3
  ---------------------------------------------------------------------------*/

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