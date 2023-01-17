//
//  input.hpp
//  8_snake
//
//  Created by Laurent Ernst on 14.01.23.
//

#ifndef input_hpp
#define input_hpp

#include <stdio.h>

void emptyBuffer();
void quitProg();

unsigned int inputVal(int min, int max, const std::string& msg, const std::string& msgError);

#endif /* input_hpp */
