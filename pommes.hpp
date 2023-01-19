//
// Created by brian on 19.01.23.
//

#ifndef TP8_POMMES_HPP
#define TP8_POMMES_HPP

class Pomme {
public:
    // --- Constructeur --- //
    Pomme(const unsigned int id,
          unsigned int posX,
          unsigned int posY,
          bool estMangee);

    // --- Get et set --- //

    unsigned int getId() const;
    unsigned int getPosX();
    unsigned int getPosY();

    void setPosX();
    void setPosY();

private:
    const unsigned int id;
    unsigned int posX;
    unsigned int posY;
    bool estMangee;
};




#endif //TP8_POMMES_HPP
