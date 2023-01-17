//
//  display.hpp
//  8_snake
//
//  Created by Laurent Ernst on 14.01.23.
//

#ifndef display_hpp
#define display_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

// Déclaration des fonctions
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<unsigned int>> vv);


#endif /* display_hpp */
