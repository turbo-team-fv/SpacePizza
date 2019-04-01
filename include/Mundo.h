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
        std::vector getPuntosEntrega();
        std::vector getItems();

    protected:

    private:
        std::vector< sf::Vector2f > puntosEntrega;
        std::vector< Items* > items;
        int ptoEntrgaActual;

};

#endif // MUNDO_H
