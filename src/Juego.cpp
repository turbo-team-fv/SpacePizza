#include "Juego.h"

Juego::Juego()
{
    //ctor
    jInstancia = new Juego();
}

Juego::~Juego()
{
    //dtor
}

Juego* Juego::jInstancia = 0;

Juego* Juego::getInstance()
{
    if(jInstancia==0)
    {
        jInstancia = new Juego();
    }

    return jInstancia;
}
