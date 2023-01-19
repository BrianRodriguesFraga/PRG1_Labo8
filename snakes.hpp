//
//  snakes.hpp
//  8_snake
//
//  Created by Laurent Ernst on 14.01.23.
//

#ifndef snakes_hpp
#define snakes_hpp

#include <vector>

class Snake {
public:
    // Constructeur //
    Snake(const unsigned int id, unsigned int posX, unsigned int posY, bool vie);

    // Set et get //
    unsigned int getId() const;
    unsigned int getPosX();
    unsigned int getPosY();
    bool getVie();

    // Fonctions //
    void snakesCreation();
    void snakesJouer();
    void SnakeBiteCheck(std::vector<unsigned int> Snakes);

private:
    unsigned int id;
    unsigned int posX;
    unsigned int posY;
    bool vie;
};


#endif /* snakes_hpp */
