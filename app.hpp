/*---------------------------------------------------------------------------
  Fichier     : app.hpp
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
        static App* instance;

        App(dim_t board_size, const int nb_snake);

        // Retourne la taille du plateau
        dim_t getBoardSize();

        // Créer les serpents et le plateau
        void initialize();

        // Boucle de jeux
        void run();

        // Libération de la mémoire
        ~App();

        // Retourne une position aléatoire sur le plateau
        position_t randomBoardPosition();

        // Retourne le serpent à la position x, y sinon retourne null
        Snake* getSnakeAtPosition(int x, int y);

    private:
        Render* render;

        std::vector<Snake*> snakes;

        dim_t board_size;
};

#endif