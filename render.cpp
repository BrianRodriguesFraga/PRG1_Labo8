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