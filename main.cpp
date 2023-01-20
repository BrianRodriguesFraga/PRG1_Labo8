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

#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <string>

#include "types.hpp"
#include "app.hpp"


// Déclaration des constantes
const int  MIN_LARGEUR    = 50;
const int  MAX_LARGEUR    = 1200;

const int  MIN_HAUTEUR    = 50;
const int  MAX_HAUTEUR    = 800;

const int  MIN_NBR_SNAKES = 2;
const int  MAX_NBR_SNAKES = 1000;


using namespace std;


int askForValue(string message, const int min, const int max)
{
  int input;
  bool check = false;

  while (!check)
  {
    cout << setw(12) << left << message << right << " [" << min << ".." << max << "] : ";

    cin >> input;

    check = cin.fail() || min > input || max < input;

    if (!check)
    {
      cin.clear(); 
      cout << "La valeur entrée est incorrect." << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  return input;
}


int main() 
{
  App* program;
    
  // --- Début du programme --- //
  cout << "Ce programme ..." << endl;

  // Paramètre de la partie
  dim_t board_size;
  board_size.width = askForValue("largeur", MIN_LARGEUR, MAX_LARGEUR);
  board_size.height = askForValue("hauteur", MIN_HAUTEUR, MAX_HAUTEUR);

  int nb_snake = askForValue("nbre serpent", MIN_NBR_SNAKES, MAX_NBR_SNAKES);


  // Creation de la partie
  program = new App(board_size, nb_snake);

  // Initialization de la partie
  program->initialize();

  // Démarrage et déroulement de la partie
  program->run();

  // Fin de la partie et libération de la mémoire
  program->free();
  delete program;

  cout << "Fin du programme." << endl
       << "Appuyer sur une touche pour quitter." << endl;

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
