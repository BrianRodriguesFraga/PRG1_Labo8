//------------------------------------------------------------------------------
// Nom              : Labo 8 - Snake
// Fichier          : land.cpp
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

#include <iostream>

#include "land.hpp"

using namespace std;

Land::Land(const unsigned width, const unsigned length) : maxWidth(width), maxLength(length) {}

unsigned int Land::surface() {
    return maxWidth * maxLength;
}
