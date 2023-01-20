/*---------------------------------------------------------------------------
  Fichier     : pommes.hpp
  Nom du labo : TP8 - Snake
  Auteur(s)   : Ernst Laurent - Rodrigues Fraga Brian
  Date        : 21.01.2022
  But         : Nous souhaitons simuler des serpents allant chercher des pommes. Lors de leurs
                déplacements, les serpents s’attaquent entre eux.
                La partie se termine lorsque qu’un seul serpent est en jeu.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.3.0
  IDE         : Clion 2022.3
  ---------------------------------------------------------------------------*/

#ifndef TP8_POMMES_HPP
#define TP8_POMMES_HPP

#include "types.hpp"

class Snake;

class Pomme {
public:
    // Constructeur //
    Pomme(unsigned int id, position_t position, Snake* snake);

    // Get et set //
    unsigned int getId() const;

    // Retourne la position de la pomme
    position_t getPosition();

    // Défini la position de la pomme
    void setPosition(position_t position);

    // Retourne le serpent
    Snake* getSnake();

    // Méthode exécuté après chaque frame (rendu graphique)
    void draw(Render* renderer);

private:
    unsigned int id;

    Snake* serpent;

    position_t position;
};

#endif //TP8_POMMES_HPP
