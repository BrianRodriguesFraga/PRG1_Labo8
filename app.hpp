/*---------------------------------------------------------------------------
  Fichiers    : app.hpp et app.cpp
  Nom du labo : TP8 - Snake
  Auteur(s)   : Ernst Laurent - Rodrigues Fraga Brian
  Date        : 20.01.2022
  But         : Nous souhaitons simuler des serpents allant chercher des pommes. Lors de leurs
                déplacements, les serpents s’attaquent entre eux.
                La partie se termine lorsque qu’un seul serpent est en jeu.

  Compilateur : gcc version 11.3.0
  IDE         : Clion 2022.3
  ---------------------------------------------------------------------------*/

#ifndef app_hpp
#define app_hpp

#include <vector>

#include "types.hpp"
#include "render.hpp"
#include "snakes.hpp"

// Déclaration variable constante de taille serpent = 10
const int SNAKE_INIT_SIZE = 10;

class App
{
public:
    // ----- Constructeur ----- //
    static App* instance;

    App(dim_t board_size, const int nb_snake);

    // ----- Destructeur ----- //

    ~App();

    // ----- Get et set ----- //

    // Retourne la taille du plateau
    dim_t getBoardSize();

    // Retourne le serpent à la position x, y sinon retourne null
    Snake* getSnakeAtPosition(int x, int y);

    // Retourne le nombre de snakes
    int getNbrSnakes();

    // Retourne le pointeur du snake
    Snake* getSnake(int index);

    // ----- Méthodes ----- //

    // Créer les serpents et le plateau
    void initialize();

    // Boucle de jeux
    void run();

    // Retourne une position aléatoire sur le plateau
    position_t randomBoardPosition();


private:
    Render* render;

    std::vector<Snake*> snakes;

    dim_t board_size;
};

#endif