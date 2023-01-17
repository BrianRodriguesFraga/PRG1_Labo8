//
//  random.cpp
//  8_snake
//
//  Created by Laurent Ernst on 15.01.23.
//

#include <iostream>

#include "random.hpp"

using namespace std;

Random::Random(unsigned int randomMin, unsigned int randomMax) : RANGE_FROM(randomMin), RANGE_TO(randomMax){};

unsigned int Random::drawNumber() {
    std::random_device                          rand_dev;
    std::default_random_engine                  generator(rand_dev());
    std::uniform_int_distribution<unsigned int> distr(RANGE_FROM, RANGE_TO);
    
    unsigned int randomNumber = distr(generator);
    
    return randomNumber;
}

