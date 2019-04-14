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

void EFin::Init()
{

}

void EFin::HandleInput(RenderWindow * ventana)
{

}
void EFin::Update()
{

}
void EFin::Draw(RenderWindow * ventana)
{

}
