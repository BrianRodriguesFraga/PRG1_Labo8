//------------------------------------------------------------------------------
// Nom              : Labo 8 - Snake
// Fichier          : main.cpp
// Auteur(s)        : Brian Rodrigues Fragas - Laurent ERNST
// Courriel(s)      : laurent.ernst@heig-vd.ch
// Git              : https://github.com/laurent-ernst
// Date             : 11.01.23
// But              :
// Modification(s)  :
// Remarque(s)      :
// IDE              : Xcode
// Compilateur      : g++
//------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <algorithm>
#include <SDL2/SDL.h>

#include "snakes.hpp"
#include "land.hpp"

using namespace std;

int main() {
    
    vector<int> vSnake = {1, 5, 5};
    
    
    
    //--------------------------------------------------------------------------
    //    SDL settings
    //--------------------------------------------------------------------------
    const int  SCREEN_WIDTH  =  500;    // largueur fenêtre
    const int  SCREEN_HEIGTH =  500;    // hauteur fenêtre
    const int  NBRE_VALUES   =   20;    //nombre de barres
    const int  SDL_DELAY     =  100;    // vitesse
    const int   SCALE       =    10;

    
    Land land(SCREEN_WIDTH , SCREEN_HEIGTH);
    
    
    
    // SDL library
    SDL_Window*    window         = nullptr;
    SDL_Renderer*  renderer       = nullptr;
    SDL_Event      event;
    bool           appIsRunning   = true;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN, &window, &renderer);
    
    if (window == nullptr or renderer == nullptr) {
       cout << "SDL not ready ... quitting" << endl;
       return EXIT_FAILURE;
    }
    
    SDL_SetWindowTitle(window, "Labo 8 - SNAKE");
    
    SDL_RenderSetScale(renderer, SCALE, SCALE) ;

//    // populate a random vector<int>
//    random_device rd;
//    uniform_int_distribution d(1, NBRE_VALUES);
//    vector<int> v(NBRE_VALUES);
//    for (int& e : v)
//       e = d(rd);

    while(appIsRunning) {
       
         //-----------------------------------------------------------------
         //    SDL drawing
         //-----------------------------------------------------------------
         
        // affiche la fenêtre
        SDL_PollEvent(&event);
         if (event.type == SDL_QUIT) {
            appIsRunning = false;
            break;
         }
         
         // efface le contenu de la fenêtre
         SDL_SetRenderDrawColor(renderer, 127, 221, 76, SDL_ALPHA_OPAQUE);
         SDL_RenderClear(renderer);

          { // boucle pour générer l'image
              SDL_Point headSnake;
              headSnake.x = 5;
              headSnake.y = 5;
              SDL_SetRenderDrawColor(renderer, 90, 58, 34, SDL_ALPHA_OPAQUE);
              SDL_RenderDrawPoint(renderer, headSnake.x, headSnake.y);
              SDL_SetRenderDrawColor(renderer, 184, 32, 16, SDL_ALPHA_OPAQUE);
              SDL_RenderDrawLine(renderer, headSnake.x+1, headSnake.y, headSnake.x+10, headSnake.y);
          }
         
          // SDL display the window
         SDL_RenderPresent(renderer);
         SDL_Delay(SDL_DELAY);
        
    }  // app running

    cout << "press ENTER to quit ...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // clear SDL ressources
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
