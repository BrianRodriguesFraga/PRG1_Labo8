/*---------------------------------------------------------------------------
  Fichier     : render.cpp
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

#include <exception>
#include <string>
#include "render.hpp"

using namespace std;

Render::Render(dim_t wsize, int scale)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(wsize.width * scale, wsize.height * scale, SDL_WINDOW_SHOWN, &window, &renderer);

	SDL_SetWindowTitle(window, "Snake");
	SDL_RenderSetScale(renderer, scale, scale);
}


Render::~Render()
{
	if (renderer != nullptr)
	{
		SDL_DestroyRenderer(renderer);
	}

	if (window != nullptr)
	{
		SDL_DestroyWindow(window);
	}
}


void Render::draw_board()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
}


void Render::update()
{
	SDL_RenderPresent(renderer);
}


SDL_Renderer* Render::getRenderer()
{
	return renderer;
}


SDL_Window* Render::getWindow()
{
	return window;
}