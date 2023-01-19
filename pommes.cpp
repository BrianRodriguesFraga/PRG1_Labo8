//
// Created by brian on 19.01.23.
//

#include "pommes.hpp"

Pomme::Pomme(const unsigned id,
             unsigned int posX,
             unsigned int posY,
             bool estMangee);

// --- get et set --- //

unsigned int Pomme::getId() const {
    return this->id;
}

unsigned int Pomme::getPosX() {
    return this->posX;
}

unsigned int Pomme::getPosY() {
    return this->posY;
}
