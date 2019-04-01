#ifndef MUNDO_H
#define MUNDO_H
#include <vector>
#include <SFML/Graphics.hpp>"
#include <iostream>
#include "Item.h"

using namespace std;

class Mundo
{
    public:
        Mundo();
        virtual ~Mundo();
        int getPtoEntregaActual();
        std::vector< sf::Vector2f > getPuntosEntrega();
        std::vector<Item*> getItems();

    protected:

    private:
        std::vector< sf::Vector2f > puntosEntrega;
        std::vector< Item* > items;
        int ptoEntrgaActual;

};

#endif // MUNDO_H
