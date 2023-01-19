//
//  input.cpp
//  8_snake
//
//  Created by Laurent Ernst on 14.01.23.
//

#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

#include "input.hpp"

using namespace std;

// Fonctions interne au fichier //

void emptyBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ---------------------------- //
//
// Fonctions accessibles depuis le fichier .h //

void demanderEntreeUtilisateur(const int& typeMessage ,const unsigned int& min, const unsigned int& max) {
    // Déclaration de variables //
    const int   WIDTH               = 12;
    string      message                 ;
    bool        errorFlux               ;
    int         entreeUtilisateur       ;

    // définition du type de message à afficher //
    switch (typeMessage) {
        case 0: message = "largeur";
            break;
        case 1: message = "hauteur";
            break;
        case 2: message = "nbre snakes";
            break;
        default: message = "??? (erreur !)";
    }

    // Demande et vérifie l'entrée utilisateur //
    do {
        cout << setw(WIDTH) << left << message << right << " [" << min << ".." << max << "] : ";
        errorFlux = false;
        if (!(cin >> entreeUtilisateur) || min > int(entreeUtilisateur) || int(entreeUtilisateur) > max) {
            errorFlux = true;
            cin.clear();
            cout << entreeUtilisateur << " : " << "Cette valeur est incorrect." << endl;
        }
        emptyBuffer();
    }
    while (errorFlux);
}

