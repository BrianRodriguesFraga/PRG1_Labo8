#include "pommes.hpp"

// ----- Constructeur ----- //

Pomme::Pomme(position_t position, Snake* snake) {
    this->position = position;
    this->serpent = snake;
}


// ----- Get et set ----- //

position_t Pomme::getPosition() {
    return this->position;
}

void Pomme::setPosition(position_t position) {
    this->position = position;
}

Snake* Pomme::getSnake() {
    return this->serpent;
}

void Pomme::draw(Render* render) const
{
    SDL_Renderer* renderer = render->getRenderer();
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(renderer, position.x, position.y);
}