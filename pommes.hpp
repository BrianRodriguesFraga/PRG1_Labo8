//
// Created by brian on 19.01.23.
//

#ifndef TP8_POMMES_HPP
#define TP8_POMMES_HPP

#include "types.hpp"

class Snake { };

class Pomme {
public:
    // Constructeur //
    Pomme(unsigned int id, position_t position, Snake* snake);

    // Get et set //
    unsigned int getId();

    // Retourne la position de la pomme
    position_t getPosition();

    // Défini la position de la pomme
    void setPosition(position_t position);

private:
    unsigned int id;

    Snake* serpent;

    position_t position;
};

#endif //TP8_POMMES_HPP
