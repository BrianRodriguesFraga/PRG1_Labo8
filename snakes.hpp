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
    void snakesCreation();
    void snakesJouer();
    void SnakeBiteCheck(std::vector<std::vector<unsigned int>> Snakes);

private:
    unsigned int id;
    unsigned int posX;
    unsigned int posY;
    unsigned int longueur;
};


#endif /* snakes_hpp */
