//
//  random.hpp
//  8_snake
//
//  Created by Laurent Ernst on 15.01.23.
//

#ifndef random_hpp
#define random_hpp

#include <stdio.h>
#include <random>

class Random {
public:
    Random(unsigned int randomMin, unsigned int randomMax);
    unsigned int drawNumber();
private:
    const unsigned int RANGE_FROM;
    const unsigned int RANGE_TO;
};

#endif /* random_hpp */
