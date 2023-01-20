//
//  snakes.hpp
//  8_snake
//
//  Created by Laurent Ernst on 14.01.23.
//

#ifndef snakes_hpp
#define snakes_hpp

#include <vector>

#include "types.hpp"
#include "render.hpp"
#include "pommes.hpp"

class Snake {
public:
    // Constructeur //
    Snake(const unsigned int id, position_t position);

    // Libére la mémoire
    void free();

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

    // Retourne true si la position x,y est la tête
    bool isHead(int x, int y);

    // Retourne true si le serpent occupe cette position
    bool isBody(int x, int y);

    // Coupe le serpent au position x,y
    void split(int x, int y);
    

    // Méthode exécuté pour chaque frame
    void update();

    // Méthode exécuté après chaque frame (rendu graphique)
    void draw(Render* renderer);

private:
    unsigned int id;

    std::vector<position_t> positions;

    Pomme* pomme;

    bool vie;
};


#endif /* snakes_hpp */
