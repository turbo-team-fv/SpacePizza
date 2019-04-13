#include "Jugador.h"

Jugador::Jugador(): pState() /**Asi inicializamos de mejor forma objetos que son intrinsecos del padre**/
{
    //ctor
    /**Funcionamiento: le digo la ruta de la textura y el numero de animaciones**/
    jugador_sprite= new SuperSprite("assets/jugador/sp_alien_texture.png",4,0.6,true);
    jugador_sprite->addFrame(sf::IntRect(50, 52,40, 44),0);
    jugador_sprite->addFrame(sf::IntRect(2, 50,40, 46),0);

}

PhysicsState Jugador::getPhysicsState()
{
    return pState;
}


void Jugador::updateJugador(bool eRight,bool eLeft,bool eUp,bool eDown, sf::Time et)
{

    double x=0,y=0,potencia=50;
    jugador_sprite->setAnimation(0);

    if(eRight)
    {
        //La tecla Derecha está pulsada:
        x=potencia;

    }
    if(eLeft)
    {
        x=-potencia;
        //La tecla Izquierda está pulsada:
    }
    if(eUp)
    {
        y=-potencia;
        //La tecla Arriba está pulsada:
    }
    if(eDown)
    {
        y=potencia;
        //La tecla Abajo está pulsada:
    }

    pState.Move(x,y,true);//Cambia el booleano para quitar aceleracion o ponerla
    pState.updatePhysicsState(et);

}


void Jugador::drawJugador(sf::RenderWindow *w, double i)
{

    /** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    this->jugador_sprite->drawSuperSprite(this->getPhysicsState().getPastState(),this->getPhysicsState().getActualState(),w,i);

}

Jugador::~Jugador()
{
    //dtor
}
