//------------------------------------------------------------------------------
// Nom              : Labo 8 - Snake
// Fichier          : snakes.cpp
// Auteur(s)        : Brian Rodrigues Fragas - Laurent ERNST
// Courriel(s)      : laurent.ernst@heig-vd.ch
// Git              : https://github.com/laurent-ernst
// Date             : 13.01.23
// But              :
// Modification(s)  :
// Remarque(s)      :
// IDE              : Xcode
// Compilateur      : g++
//------------------------------------------------------------------------------


#include "snakes.hpp"

Snake::Snake(unsigned int id, unsigned int coordX, unsigned int coordY, unsigned int length): coordXSnake(coordX), coordYSnake(coordY) {};

unsigned int Snake::showSnake(unsigned int coordX, unsigned int coordY) {
    return coordXSnake = coordX, coordYSnake = coordY;
}
