/*---------------------------------------------------------------------------
  Fichier     : app.cpp
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

#include <chrono>
#include <thread>
#include <cstdlib>

#include "app.hpp"
#include "types.hpp"

using namespace std;


const int RENDER_SCALE = 5;
const int TIME_SCALE   = 50;


App::App(dim_t board_size, const int nb_snake)
{
    this->board_size = board_size;

    for (int i = 0; i < nb_snake; ++i)
    {
        this->snakes.push_back(
            new Snake(i, position_t(-1, -1), this)
        );
    }

    render = new Render(this->board_size, RENDER_SCALE);
}


void App::initialize()
{
    srand((unsigned)time(NULL));

    // Place les serpents aléatoirement et les pommes sur le plateau
    for (int i = 0; i < this->snakes.size(); ++i)
    {
        Snake* snakeAt = nullptr;

        position_t snake_pos;

        do
        {
            snake_pos = randomBoardPosition();
            snakeAt = getSnakeAtPosition(snake_pos.x, snake_pos.y);
        } while (snakeAt != nullptr);

        this->snakes[i]->setPosition(snake_pos);


        position_t apple_pos = randomBoardPosition();

        do
        {
            apple_pos = randomBoardPosition();
        } while (this->snakes[i]->isBody(apple_pos.x, apple_pos.y));

        this->snakes[i]->getPomme()->setPosition(apple_pos);
    }
}


void App::run()
{
    bool end = false;

    while (!end)
    {
        // Events
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
                case SDL_QUIT:
                    end = true;
                    break;
                default:
                    break;
            }
        }

        // Joue un tour de jeu
        for (int i = 0; i < this->snakes.size(); ++i)
        {
            this->snakes[i]->update();
        }

        //
        int nbSnakeAlive = 0;
        for (int i = 0; i < this->snakes.size(); ++i) {
            if (this->snakes[i]->getLength() > 0) {
                ++nbSnakeAlive;
            }
        }
        if (nbSnakeAlive == 1) {
            end = true;
        }

        // Dessine le plateau
        this->render->draw_board();

        for (int i = 0; i < this->snakes.size(); ++i)
        {
            this->snakes[i]->draw(render);
        }

        this->render->update();

        // Attend x ms avant de jouer le prochain "tour"
        this_thread::sleep_for(chrono::milliseconds(TIME_SCALE));
    }



}


dim_t App::getBoardSize()
{
    return this->board_size;
}


App::~App()
{
    for (int i = 0; i < this->snakes.size(); ++i)
    {
        delete this->snakes[i];
    }

    delete render;
}


position_t App::randomBoardPosition()
{
    return position_t(
        rand() % this->board_size.width,
        rand() % this->board_size.height
    );
}


Snake* App::getSnakeAtPosition(int x, int y)
{
    Snake* r = nullptr;

    for (int i = 0; i < this->snakes.size(); ++i)
    {
        position_t pos = this->snakes[i]->getPosition();

        if (pos.x == x && pos.y == y)
        {
            r = this->snakes[i];
            break;
        }
    }

    return r;
}

int App::getNbrSnakes() {
    return (int)this->snakes.size();
}

Snake* App::getSnake(int index) {
    return this->snakes[index];
}


