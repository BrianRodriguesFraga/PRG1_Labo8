/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : TP8 - Snake
  Auteur(s)   : Ernst Laurent - Rodrigues Fraga Brian
  Date        : 15.11.2022
  But         : Nous souhaitons simuler des serpents allant chercher des pommes. Lors de leurs
                déplacements, les serpents s’attaquent entre eux.
                La partie se termine lorsque qu’un seul serpent est en jeu.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.3.0
  IDE         : Clion 2022.3
  ---------------------------------------------------------------------------
*/

#include "affichage.hpp"
#include "entree.hpp"
#include "snakes.hpp"
#include "pommes.hpp"

using namespace std;

int main() {
    // --- Déclarations de variables --- //
    const unsigned int  MIN_LARGEUR    = 50;
    const unsigned int  MIN_HAUTEUR    = 50;
    const unsigned int  MIN_NBR_SNAKES = 2;
    const unsigned int  MAX_LARGEUR    = 1200;
    const unsigned int  MAX_HAUTEUR    = 800;
    const unsigned int  MAX_NBR_SNAKES = 1000;

    enum TypeMessage {largeur, hauteur, nbrSnakes};

    // --- Début du programme --- //
    afficherBienvenue();
    demanderEntreeUtilisateur(largeur, MIN_LARGEUR, MAX_LARGEUR);
    demanderEntreeUtilisateur(hauteur, MIN_HAUTEUR, MAX_HAUTEUR);
    demanderEntreeUtilisateur(nbrSnakes, MIN_NBR_SNAKES, MAX_NBR_SNAKES);

    //snakesCreation();
    //snakesJouer();

    afficherFin();

    return EXIT_SUCCESS;
}









//int main() {
//    unsigned int lengthSnake = 10;
//
//    for (unsigned int i = 0; i < nbrSnakes; i++) {
//
//        Random direction(0,3);
//        unsigned int directionRandom = direction.drawNumber();
//
//        Random x(0,100);
//        unsigned int randomX = x.drawNumber();
//
//        Random y(0,100);
//        unsigned int randomY = y.drawNumber();
//
//        Snake fSnake(randomX, randomY, directionRandom, lengthSnake);
//
//        vector<vector<unsigned int>> vSnake = fSnake.createdSnake();
//
//        // Affichage pour les tests
//        cout << "Snake # " << i << ", Direction : " << directionRandom <<  endl;
//
//
//        for (unsigned int i = 0; i < 10; i++) {
//            cout << "[";
//            cout << vSnake[i][0];
//            cout << ", ";
//            cout << vSnake[i][1];
//            cout << ", ";
//            cout << vSnake[i][2];
//            cout << "],";
//            }
//        cout << "]" << endl << endl;
//    }
//}
