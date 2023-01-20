/*---------------------------------------------------------------------------
  Fichier     : pommes.cpp
  Nom du labo : TP8 - Snake
  Auteur(s)   : Ernst Laurent - Rodrigues Fraga Brian
  Date        : 20.01.2022
  But         : Nous souhaitons simuler des serpents allant chercher des pommes. Lors de leurs
                déplacements, les serpents s’attaquent entre eux.
                La partie se termine lorsque qu’un seul serpent est en jeu.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.3.0
  IDE         : Clion 2022.3
  ---------------------------------------------------------------------------*/

#include "pommes.hpp"

Pomme::Pomme(unsigned int id, position_t position, Snake* snake) {
    this->id = id;
    this->position = position;
    this->serpent = snake;
}

// --- get et set --- //

unsigned int Pomme::getId() const {
    return this->id;
}

position_t Pomme::getPosition() {
    return this->position;
}

// Défini la position de la pomme
void Pomme::setPosition(position_t position) {
    this->position = position;
}

Snake* Pomme::getSnake() {
    return this->serpent;
}

void Pomme::draw(Render* render) 
{
    SDL_Renderer* renderer = render->getRenderer();
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(renderer, position.x, position.y);
}