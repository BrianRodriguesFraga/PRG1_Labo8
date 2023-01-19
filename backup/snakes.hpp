//
//  snakes.hpp
//  8_snake
//
//  Created by Laurent Ernst on 14.01.23.
//

#ifndef snakes_hpp
#define snakes_hpp

#include <stdio.h>
#include <vector>

class Snake {
public:
    Snake(unsigned int randomX, unsigned int randomY, unsigned int direction, unsigned int lengthSnake);
    std::vector<std::vector<unsigned int>> createdSnake();
    void SnakeBiteCheck(std::vector<std::vector<unsigned int>> actualSnakes);

private:
    unsigned int coordX;
    unsigned int coordY;
    unsigned int cap;
    unsigned int length;
};

//std::vector<std::vector<unsigned int>> Snake(unsigned int randomX, unsigned int randomY, unsigned int direction, unsigned int lengthSnake);

#endif /* snakes_hpp */
