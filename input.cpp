//
//  input.cpp
//  8_snake
//
//  Created by Laurent Ernst on 14.01.23.
//

#include <iostream>
#include <limits>

#include "input.hpp"

using namespace std;

void emptyBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void quitProg() {
    cout << endl << "Presser ENTER pour quitter le programme" << endl;
    emptyBuffer();
}

unsigned int inputVal (int min, int max, const string& msg, const string& msgError) {
    unsigned int val;
    bool errorFlux;
    
    do {
        cout << msg << " [" << min << ".." << max << "] : ";
        errorFlux = false;
        
        if (not(cin >> val) or min > int(val) or int(val) > max) {
            errorFlux = true;
            cin.clear();
            cout << val << " : " << msgError << endl;
        }
        emptyBuffer();
    }
    while (errorFlux);
    return val;
}
