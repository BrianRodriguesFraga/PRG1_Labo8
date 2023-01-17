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

Snake::Snake(unsigned int randomX, unsigned int randomY, unsigned int direction, unsigned int lengthSnake) : coordX(randomX), coordY(randomY), cap(direction), length(lengthSnake) {}

vector<vector<unsigned int>> Snake::createdSnake() {
    vector<vector<unsigned int>> vSnake(length, vector<unsigned int>(3));
    for (unsigned int i = 0; i < length; i++) {
            vSnake[i][0] = i;
            for (unsigned int j = 0; j < length; j++) {
                vSnake[i][1] = coordX;
                vSnake[i][2] = coordY;
            }
            // NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3
            if (cap == 0) {
                coordY--;
            } else if (cap == 1) {
                coordX--;
            } else if (cap == 2) {
                coordY++;
            } else {
                coordX++;
            }
        }
    return vSnake;
}
