/*---------------------------------------------------------------------------
  Fichiers    : pommes.hpp et pommes.cpp
  Nom du labo : TP8 - Snake
  Auteur(s)   : Ernst Laurent - Rodrigues Fraga Brian
  Date        : 20.01.2022
  But         : Nous souhaitons simuler des serpents allant chercher des pommes. Lors de leurs
                déplacements, les serpents s’attaquent entre eux.
                La partie se termine lorsque qu’un seul serpent est en jeu.

  Compilateur : gcc version 11.3.0
  IDE         : Clion 2022.3
  ---------------------------------------------------------------------------*/

#ifndef TP8_POMMES_HPP
#define TP8_POMMES_HPP

#include "types.hpp"
#include "render.hpp"

class Snake;

class Pomme {
public:
    // ----- Constructeur ----- //

    Pomme(position_t position, Snake* snake);

    // ----- Get et set ----- //

    // Retourne la position de la pomme
    position_t getPosition();

    // Défini la position de la pomme
    void setPosition(position_t position);

    // Retourne le serpent
    Snake* getSnake();

    // ----- Méthodes ----- //

    // Méthode exécuté après chaque frame (rendu graphique)
    void draw(Render* render) const;

private:
    Snake* serpent;

    position_t position;
};

#endif //TP8_POMMES_HPP
