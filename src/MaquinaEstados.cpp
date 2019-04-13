#include "MaquinaEstados.h"

MaquinaEstados::MaquinaEstados()
{
    //ctor
}

MaquinaEstados::~MaquinaEstados()
{
    //dtor
}

void MaquinaEstados::comenzarJuego()
{
    eJugando = new EJugando();
}

void MaquinaEstados::finalizarJuego()
{
    delete eJugando();
    eFin = new EFin();
}

void MaquinaEstados::sacarMenu()
{
    eMenu = new Emenu();
}

