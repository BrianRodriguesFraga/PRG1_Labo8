//
//  engagementRules.hpp
//  8_snake
//
//  Created by Laurent Ernst on 17.01.23.
//

#ifndef engagementRules_hpp
#define engagementRules_hpp

#include <stdio.h>
#include <vector>

class Rules {
public:
    Rules(unsigned int randomX, unsigned int randomY,unsigned int nbrSnakes, unsigned int appleId, unsigned int pointApple);
    
private:
    std::vector<unsigned int> createdApple(unsigned int nbrSnakes, unsigned int appleId, unsigned int pointApple);
    
    unsigned int id;
    unsigned int nbr;
    unsigned int point;
    unsigned int coordX;
    unsigned int coordY;
};

#endif /* engagementRules_hpp */
