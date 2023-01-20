#ifndef app_hpp
#define app_hpp

#include <vector>

#include "types.hpp"
#include "render.hpp"
#include "snakes.hpp"

const int SNAKE_INIT_SIZE = 10;

class App
{
    public:
        static App* instance = nullptr;


        App(dim_t board_size, const int nb_snake);

        // Retourne la taille du plateau
        dim_t getBoardSize();

        // Créer les serpents et le plateau
        void initialize();

        // Boucle de jeux
        void run();

        // Libération de la mémoire
        void free();

        // Retourne une position aléatoire sur le plateau
        position_t randomBoardPosition();

        // Retourne le serpent a la position x,y sinon retourne null
        Snake* getSnakeAtPosition(int x, int y);

    private:
        Render* render;

        std::vector<Snake*> snakes;

        dim_t board_size;
};

#endif