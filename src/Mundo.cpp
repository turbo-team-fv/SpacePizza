#include "Mundo.h"

Mundo::Mundo() {
    //ctor
    ptoEntrgaActual = 0;
}

int Mundo::getPtoEntregaActual() {
    return ptoEntrgaActual;
}

std::vector<Item*> Mundo::getItems() {
    return items;
}

std::vector<sf::Vector2f> Mundo::getPuntosEntrega() {
    return puntosEntrega;
}

Mundo::~Mundo()
{
    //dtor
}
