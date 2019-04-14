#include "EJugando.h"

EJugando::EJugando()
{
    //ctor
}

EJugando* EJugando::eJugandoInstancia = 0;

EJugando* EJugando::getInstance()
{
    if(eJugandoInstancia == 0)
    {
        eJugandoInstancia = new EJugando();
    }
    return eJugandoInstancia;
}

void EJugando::Init()
{

}

void EJugando::HandleInput(RenderWindow * ventana)
{

}
void EJugando::Update()
{

}
void EJugando::Draw(RenderWindow * ventana)
{

}

