//------------------------------------------------------------------------------
// Nom              : Labo 8 - Snake
// Fichier          : snakes.hpp
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

#ifndef snakes_hpp
#define snakes_hpp

#include <stdio.h>
#include <iostream>

class Snake {
public:
    //--------------------------------------------------------------------------
    // Constructeur
    //--------------------------------------------------------------------------
    Snake(unsigned int id, unsigned int coordX, unsigned int coordY, unsigned int length);
    unsigned int showSnake(unsigned int coordX, unsigned int coordY);
    
private:
    unsigned int idSnake;
    unsigned int coordXSnake;
    unsigned int coordYSnake;
    unsigned int lengthSnake;
};



#endif /* snakes_hpp */
