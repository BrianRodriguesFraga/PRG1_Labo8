/*---------------------------------------------------------------------------
  Fichier     : snakes.hpp
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

#ifndef snakes_hpp
#define snakes_hpp

#include <vector>

#include "types.hpp"
#include "render.hpp"
#include "pommes.hpp"


class Snake {
public:
    // Constructeur //
    Snake(unsigned int id, position_t position);

    // Libére la mémoire
    ~Snake();

    // Set et get //
    unsigned int getId() const;

    // Retourne la longueur du serpent
    int getLength();

    // Retourne la position du serpent
    position_t getPosition();

    // Définie la position du serpent initial
    void setPosition(position_t position);

    // Retourne la pomme du serpent
    Pomme* getPomme();

    // Fonctions //

    // Retourne true si la position x, y est la tête
    bool isHead(int x, int y);

    // Retourne true si le serpent occupe cette position
    bool isBody(int x, int y);

    // Coupe le serpent à la position x, y
    void split(int x, int y);

    // Fait bouger le serpent dans une direction
    void move(MoveType direction);


    // Méthode exécutée pour chaque frame
    void update();

    // Méthode exécutée après chaque frame (rendu graphique)
    void draw(Render* render);

private:
    unsigned int id;

    std::vector<position_t> positions;

    Pomme* pomme;

};


#endif /* snakes_hpp */
