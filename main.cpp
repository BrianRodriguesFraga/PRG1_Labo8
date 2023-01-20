/*---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : TP8 - Snake
  Auteur(s)   : Ernst Laurent - Rodrigues Fraga Brian
  Date        : 20.01.2022
  But         : Nous souhaitons simuler des serpents allant chercher des pommes. Lors de leurs
                déplacements, les serpents s’attaquent entre eux.
                La partie se termine lorsque qu’un seul serpent est en jeu.

  Remarques   : Il est connu que dans les autres fichiers que le code affiche des warnings.
                Cela n'empêche pas le fonctionnement du jeu.

  Compilateur : gcc version 11.3.0
  IDE         : Clion 2022.3
  ---------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>

#include "types.hpp"
#include "app.hpp"


using namespace std;

// ----- Déclaration des constantes ----- //
const int  MIN_LARGEUR = 50;
const int  MAX_LARGEUR = 1200;

const int  MIN_HAUTEUR = 50;
const int  MAX_HAUTEUR = 800;

const int  MIN_NBR_SNAKES = 2;
const int  MAX_NBR_SNAKES = 1000;

// ----- Fonctions ----- //
int askForValue(const string& message, const int min, const int max)
{
    int input;

    bool fail = true;
    while (fail)
    {
        cout << setw(12) << left << message << right << " [" << min << ".." << max << "] : ";

        cin >> input;

        fail = cin.fail() || min > input || max < input;

        if (fail)
        {
            cin.clear();
            cout << "La valeur entrée est incorrect." << endl;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return input;
}

// ----- Début du programme ----- //
int main()
{
    App* program;

    cout << "Ce programme ..." << endl;

    // Récupérer les paramètres de la partie
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
    delete program;

    cout << "Fin du programme." << endl
        << "Appuyer sur une touche pour quitter." << endl;

    return EXIT_SUCCESS;
}
