//
//  main.cpp
//  8_snake
//
//  Created by Laurent Ernst on 14.01.23.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>

#include "display.hpp"
#include "snakes.hpp"
#include "input.hpp"
#include "random.hpp"

using namespace std;

using vWidth = vector<int>;
using vHeigth = vector<vWidth>;

int main() {
    // Invitation à choisir la taille de l'écran et le nombre de serpents
    cout << "Ce programme ..." << endl;
    const string msgWidth = "Largeur";
    const string msgHeigth = "Hauteur ";
    const string msgNbrSnake = "Nombre de serpents";
    const string msgError = "Valeur non valide !";


    const unsigned int widthMin = 50;
    const unsigned int heigthMin = 50;
    const unsigned int widthMax = 1200;
    const unsigned int heigthMax = 800;
    const unsigned int snakeMin = 2;
    const unsigned int snakeMax = 1000;

    const unsigned int width = inputVal(widthMin, widthMax, msgWidth, msgError);
    const unsigned int heigth = inputVal(heigthMin, heigthMax, msgHeigth, msgError);
    const unsigned int nbrSnakes = inputVal(snakeMin, snakeMax, msgNbrSnake, msgError);

    // Création des serpents
    unsigned int lengthSnake = 10;
    
    for (unsigned int i = 0; i < nbrSnakes; i++) {
        
        Random direction(0,3);
        unsigned int directionRandom = direction.drawNumber();
        
        Random x(0,100);
        unsigned int randomX = x.drawNumber();
        
        Random y(0,100);
        unsigned int randomY = y.drawNumber();
        
        Snake fSnake(randomX, randomY, directionRandom, lengthSnake);
        
        vector<vector<unsigned int>> vSnake = fSnake.createdSnake();
        
        // Affichage pour les tests
        cout << "Snake # " << i << ", Direction : " << directionRandom <<  endl;


        for (unsigned int i = 0; i < 10; i++) {
            cout << "[";
            cout << vSnake[i][0];
            cout << ", ";
            cout << vSnake[i][1];
            cout << ", ";
            cout << vSnake[i][2];
            cout << "],";
            }
        cout << "]" << endl << endl;
    }
}
