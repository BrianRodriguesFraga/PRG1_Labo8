//
//  display.cpp
//  8_snake
//
//  Created by Laurent Ernst on 14.01.23.
//

#include <iostream>
#include <vector>

#include "display.hpp"

using namespace std;

ostream& operator<<(ostream& os, const vector<unsigned int> vv){
    os << "[";
    for (size_t i = 0; i < vv.size(); ++i) {
        if (i) {
            os << ", ";
        }
        os << vv[i];
    }
    os << "]";
    return os;
}


