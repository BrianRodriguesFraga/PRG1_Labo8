/*---------------------------------------------------------------------------
  Fichiers    : snakes.hpp et snakes.cpp
  Nom du labo : TP8 - Snake
  Auteur(s)   : Ernst Laurent - Rodrigues Fraga Brian
  Date        : 20.01.2022
  But         : Nous souhaitons simuler des serpents allant chercher des pommes. Lors de leurs
                déplacements, les serpents s’attaquent entre eux.
                La partie se termine lorsque qu’un seul serpent est en jeu.

  Compilateur : gcc version 11.3.0
  IDE         : Clion 2022.3
  ---------------------------------------------------------------------------*/

#ifndef snakes_hpp
#define snakes_hpp

#include <vector>

#include "types.hpp"
#include "render.hpp"
#include "pommes.hpp"
class App;


class Snake {
public:
    // ----- Constructeur ----- //

    Snake(unsigned int id, position_t position, App* app);

    // ----- Destructeur ----- //

    ~Snake();

    // ----- Get et set ----- //

    // Retourne l'ID du serpent
    unsigned int getId() const;

    // Retourne la longueur du serpent
    int getLength();

    // Retourne la position du serpent
    position_t getPosition();

    // Définie la position du serpent initial
    void setPosition(position_t position);

    // Retourne la pomme du serpent
    Pomme* getPomme();

    // ----- Méthodes ----- //

    // Retourne true si le serpent occupe cette position
    bool isBody(int x, int y);

    // Méthode exécutée pour chaque frame
    void update();

    // Méthode exécutée après chaque frame (rendu graphique)
    void draw(Render* render);

private:
    // ----- Variables ----- //

    unsigned int id;

    std::vector<position_t> positions;

    Pomme* pomme;

    App* app;

    // ----- Méthodes ----- //

    // Tue le serpent
    void kill(Snake* attacker);

    // Fait bouger le serpent dans une direction
    void move(MoveType direction);

    // Coupe le serpent à la position x, y
    int split(int x, int y);

    // Retourne true si la position x, y est la tête
    bool isHead(int x, int y);

    // Ajoute de la longueur au serpent
    void addLength(int length);

};


#endif /* snakes_hpp */
