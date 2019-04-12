#include "EJugando.h"

EJugando::EJugando()
{
    //ctor
}

EJugando* EJugando::eJugandoInstancia = 0;

EJugando* EJugando::getInstance()
{
    if(eJugandoInstancia)
    {
        eJugandoInstancia = new EJugando();
    }
    return eJugandoInstancia;
}
