#include "EFin.h"

EFin::EFin()
{
    //ctor
}

EFin* EFin::eFinInstancia = 0;

EFin* EFin::getInstance()
{
    if(eFinInstancia==0)
    {
        eFinInstancia = new EFin();
    }

    return eFinInstancia;
}