/*---------------------------------------------------------------------------
  Fichier     : snakes.cpp
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

#include <iostream>
#include <vector>
#include <random>

#include "snakes.hpp"
#include "app.hpp"

using namespace std;

// ----- Constructeur ----- //

Snake::Snake(unsigned int id, position_t position)
{
    this->id = id;

    for (int i = 0; i < 10; ++i)
    {
        this->positions.push_back(position);
    }

    pomme = new Pomme(0, position_t(0, 0), this);
};


// ----- Get et set ----- //

unsigned int Snake::getId() const {
    return this->id;
}

// Retourne la longueur du serpent
int Snake::getLength() {
    return (int) this->positions.size();
}

// Retourne la position du serpent
position_t Snake::getPosition() {
    //position du serpent;
    return this->positions[0];
}

void Snake::setPosition(position_t position) {
    for (int i = 0; i < positions.size(); ++i)
    {
        positions[i] = position;
    }
}

Pomme* Snake::getPomme() {
    return pomme;
}

// Méthodes //

// Libére la mémoire
Snake::~Snake()
{
    if (this->pomme != nullptr)
    {
        delete this->pomme;
    }
}

// Retourne true si la position x, y est la tête
bool Snake::isHead(int x, int y)
{
    return (positions.size() == 0) ? false : this->positions[0].x == x && this->positions[0].y == y;
}

// Retourne true si le serpent occupe cette position
bool Snake::isBody(int x, int y)
{
    bool r = false;

    for (size_t i = 0; i < this->positions.size(); ++i) {
        if (this->positions[i].x == x && this->positions[i].y == y) {
            r = true;
            break;
        }
    }

    return r;
}

// Coupe le serpent à la position x, y
void Snake::split(int x, int y) {
    size_t i = 0;
    int split_index = -1;

    while (split_index == -1 && i < this->positions.size()) {
        if (this->positions[i].x == x && this->positions[i].y == y) {
            split_index = (int)i;
        }
        ++i;
    }

    if (split_index != -1) {
        size_t len = this->positions.size() - (size_t)split_index;
        this->positions.resize(len);

//        position_t copy [len];     // warning voulu
//        for (int i = 0; i < len; ++i) {
//            copy[i] = this->positions[i];
//        }
//        this->positions.resize(len);
//        for (int i = 0; i < len; ++i) {
//            this->positions[i] = copy[i];
//        }

    }
}


void Snake::move(MoveType direction)
{
    if (positions.size() != 0)
    {
        position_t newPosition = positions[0];

        switch (direction)
        {
            case MoveType::Up:
                newPosition.y -= 1;
                break;
            case MoveType::Down:
                newPosition.y += 1;
                break;
            case MoveType::Left:
                newPosition.x -= 1;
                break;
            case MoveType::Right:
                newPosition.x += 1;
                break;
            default:
                break;
        }

        position_t oldPosition;
        for (int i = 0; i < positions.size(); ++i)
        {
            oldPosition = positions[i];
            positions[i] = newPosition;
            newPosition = oldPosition;
        }
    }
}


// Méthode exécutée pour chaque frame
void Snake::update()
{
    if (pomme != nullptr && positions.size() > 0)
    {
        position_t head = positions[0];
        position_t posPomme = pomme->getPosition();

        // On détermine la direction dans laquelle aller
        position_t distance = position_t(posPomme.x - head.x, posPomme.y - head.y);

        MoveType direction = MoveType::Right;

        if (distance.x * distance.x >= distance.y * distance.y)
        {
            direction = (distance.x < 0) ? MoveType::Left : MoveType::Right;
        }
        else
        {
            direction = (distance.y < 0) ? MoveType::Up : MoveType::Down;
        }

        // On bouge le serpent dans la direction
        this->move(direction);

        // On vérifie si le serpent est sur la pomme
        if (head.x == posPomme.x && head.y == posPomme.y)
        {
            // On ajoute 1 de longueur
            positions.push_back(positions[positions.size() - 1]);

            // On change la position de la pomme
            position_t posPomme = App::instance->randomBoardPosition();

            while (head.x == posPomme.x && head.y == posPomme.y)
            {
                posPomme = App::instance->randomBoardPosition();
            }

            pomme->setPosition(posPomme);
        }

        // On vérifie si le serpent est sur un autre serpent
        // TODO
    }
}

// Méthode exécutée après chaque frame (rendu graphique)
void Snake::draw(Render* render)
{
    SDL_Renderer* renderer = render->getRenderer();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    for (int i = 0; i < positions.size(); ++i)
    {
        SDL_RenderDrawPoint(renderer, positions[i].x, positions[i].y);
    }

    if (pomme != nullptr)
    {
        pomme->draw(render);
    }
}