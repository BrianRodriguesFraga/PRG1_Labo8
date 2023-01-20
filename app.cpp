#include <chrono>
#include <thread>
#include <cstdlib>

#include "app.hpp"
#include "types.hpp"

using namespace std;


App::App(dim_t board_size, const int nb_snake)
{
    App::instance = this;

    this->board_size = board_size;

    for (int i = 0; i < nb_snake; ++i)
    {
        this->snakes.push_back(
            new Snake(i, position_t(-1, -1))
        );
    }
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
        // Joue un tour de jeu
        for (int i = 0; i < this->snakes.size(); ++i)
        {
            this->snakes[i]->update();
        }

        // Déssine le plateau
        this->render->draw_board();

        for (int i = 0; i < this->snakes.size(); ++i)
        {
            this->snakes[i]->draw(render);
        }

        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}


dim_t App::getBoardSize()
{
    return this->board_size;
}


void App::free()
{
    for (int i = 0; i < this->snakes.size(); ++i)
    {
        this->snakes[i]->free();
        delete this->snakes[i];
    }
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