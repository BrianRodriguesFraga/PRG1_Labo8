/*---------------------------------------------------------------------------
  Fichier     : snakes.cpp
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

#include <iostream>
#include <vector>
#include <random>

#include "snakes.hpp"

using namespace std;

// --- Constructeur --- //

Snake::Snake(unsigned int id, position_t position) {
    this->id = id;
    this->positions.push_back(position);
};


// get et set //
unsigned int Snake::getId() const {
    return this->id;
}

// Retourne la longueur du serpent
int Snake::getLength() {
    return (int) this->positions.size();
}

// Retourne la position du serpent
position_t Snake::getPosition() {
    //position du serpent;
    return this->positions[0];
}

void Snake::setPosition(position_t position) {

}

Pomme* Snake::getPomme() {

}

// Méthodes //

// Libére la mémoire
void Snake::free() {

}

// Retourne true si la position x, y est la tête
bool Snake::isHead(int x, int y) {
    return this->positions[0].x == x && this->positions[0].y == y;
}

// Retourne true si le serpent occupe cette position
bool Snake::isBody(int x, int y) {
    bool r = false;
    for (size_t i = 0; i < this->positions.size(); ++i) {
        if (this->positions[i].x == x && this->positions[i].y == y) {
            r = true;
            break;
        }
    }
    return r;
}

// Coupe le serpent à la position x, y
void Snake::split(int x, int y) {
    size_t i = 0;
    int split_index = -1;

    while (split_index == -1 && i < this->positions.size()) {
        if (this->positions[i].x == x && this->positions[i].y == y) {
            split_index = (int)i;
        }
        ++i;
    }

    if (split_index != -1) {
        size_t len = this->positions.size() - (size_t)split_index;
        this->positions.resize(len);

//        position_t copy [len];     // warning voulu
//        for (int i = 0; i < len; ++i) {
//            copy[i] = this->positions[i];
//        }
//        this->positions.resize(len);
//        for (int i = 0; i < len; ++i) {
//            this->positions[i] = copy[i];
//        }

    }
}

// Méthode exécutée pour chaque frame
void Snake::update() {

}

// Méthode exécutée après chaque frame (rendu graphique)
void Snake::draw(Render* renderer) {

}