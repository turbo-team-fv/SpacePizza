#include "Jugador.h"

Jugador::Jugador() /**Asi inicializamos de mejor forma objetos que son intrinsecos del padre**/
{
    //ctor
    pState= new PhysicsState();
    pState->setActualState(150,250);
    /**Funcionamiento: le digo la ruta de la textura y el numero de animaciones**/
    jugador_sprite= new SuperSprite("assets/jugador/sp_alien_texture.png",4,0.6,true);
    jugador_sprite->addFrame(sf::IntRect(50, 52,40, 44),0);//iz
    jugador_sprite->addFrame(sf::IntRect(2, 50,40, 46),0);

    jugador_sprite->addFrame(sf::IntRect(6, 98,40, 46),1);//der
    jugador_sprite->addFrame(sf::IntRect(54, 100,40, 44),1);

    jugador_sprite->addFrame(sf::IntRect(8, 146,32, 46),2);//arr
    jugador_sprite->addFrame(sf::IntRect(56, 148,32, 44),2);

    jugador_sprite->addFrame(sf::IntRect(10, 4,28, 44),3);//ab
    jugador_sprite->addFrame(sf::IntRect(58, 6,28, 42),3);

       /**COLLIDERS**/
    vector <sf::Rect<float> > colinit;
    colinit.push_back(sf::FloatRect(-8,10,22,3));//arr
    colinit.push_back(sf::FloatRect(-11,-10,3,22));//der
    colinit.push_back(sf::FloatRect(13,-10,3,22));//iz
    colinit.push_back(sf::FloatRect(-8,-13,22,3));//ab
    pState->setColliders(colinit);


}

PhysicsState* Jugador::getPhysicsState()
{
    return pState;
}


void Jugador::updateJugador(bool eRight,bool eLeft,bool eUp,bool eDown, sf::Time et)
{

    double x=0,y=0,potencia=50;


    if(eRight)
    {
    jugador_sprite->setAnimation(1);
        //La tecla Derecha está pulsada:
        x=potencia;

    }
    if(eLeft)
    {
    jugador_sprite->setAnimation(0);
        x=-potencia;
        //La tecla Izquierda está pulsada:
    }
    if(eUp)
    {
    jugador_sprite->setAnimation(2);
        y=-potencia;
        //La tecla Arriba está pulsada:
    }
    if(eDown)
    {
    jugador_sprite->setAnimation(3);
        y=potencia;
        //La tecla Abajo está pulsada:
    }

    pState->Move(x,y,true);//Cambia el booleano para quitar aceleracion o ponerla
    pState->updatePhysicsState(et);

}

void Jugador::calcInter(sf::RenderWindow *w, double i)
{

    /** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    this->jugador_sprite->calcInter(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);

}

void Jugador::drawJugador(sf::RenderWindow *w, double i)
{

    /** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    this->jugador_sprite->drawSuperSprite(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);

}

Jugador::~Jugador()
{
    //dtor
}
