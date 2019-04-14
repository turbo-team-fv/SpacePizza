#include "MaquinaEstados.h"

#include "EJugando.h"

MaquinaEstados::MaquinaEstados()
{
    //ctor


}

MaquinaEstados::~MaquinaEstados()
{
    //dtor
}

void MaquinaEstados::AddState(State * state)
{
    estados.push_back(state);
}
