//------------------------------------------------------------------------------
// Nom              : Labo 8 - Snake
// Fichier          : land.hpp
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


#ifndef land_hpp
#define land_hpp

#include <stdio.h>

class Land {
public:
    Land(unsigned int width, unsigned int length);
    unsigned int surface();
private:
    const unsigned maxWidth;
    const unsigned maxLength;
};

#endif /* land_hpp */
