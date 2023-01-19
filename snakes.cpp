//
//  snakes.cpp
//  8_snake
//
//  Created by Laurent Ernst on 14.01.23.
//

#include <iostream>
#include <vector>
#include <random>

#include "snakes.hpp"

using namespace std;

// --- Constructeur --- //

Snake::Snake(const unsigned id, unsigned int posX, unsigned int posY, bool vie = 1);


// --- get et set --- //
unsigned int Snake::getId() const {
    return this->id;
}

unsigned int Snake::getPosX() {
    return this->posX;
}

unsigned int Snake::getPosY() {
    return this->posY;
}

bool Snake::getVie() {
    return this->vie;
}


// --- Fonctions --- //

void snakesCreation() {

}

void snakesJouer() {

}
