/*---------------------------------------------------------------------------
  Fichier     : types.hpp
  Nom du labo : TP8 - Snake
  Auteur(s)   : Ernst Laurent - Rodrigues Fraga Brian
  Date        : 20.01.2022
  But         : Nous souhaitons simuler des serpents allant chercher des pommes. Lors de leurs
                déplacements, les serpents s’attaquent entre eux.
                La partie se termine lorsque qu’un seul serpent est en jeu.

  Compilateur : gcc version 11.3.0
  IDE         : Clion 2022.3
  ---------------------------------------------------------------------------*/

#ifndef types_hpp
#define types_hpp

// Permet de définir le type position_t avec un x et un y
struct position_t {
    int x;
    int y;

    position_t() { x = 0; y = 0; }
    position_t(int x, int y) : x(x), y(y) { }
};

// Permet de définir le type dim_t avec la largeur et la hauteur
struct dim_t {
    int width;
    int height;

    dim_t() { width = 0; height = 0; }
    dim_t(int w, int h) : width(w), height(h) { }
};

// Permet de définir les mouvements du serpent
enum class MoveType { Left, Right, Up, Down };

#endif