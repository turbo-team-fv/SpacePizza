#include "Mundo.h"

Mundo::Mundo() {
    //ctor
    ptoEntrgaActual = 0;
}

int Mundo::getPtoEntregaActual() {
    return ptoEntrgaActual;
}

std::vector Mundo::getItems() {
    return items;
}

std::vector Mundo::getPuntosEntrega() {
    return puntosEntrega;
}

Mundo::~Mundo()
{
    //dtor
}
