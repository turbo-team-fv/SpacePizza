#include "Enemigo.h"

Enemigo::Enemigo()
{

    pState=new PhysicsState();
    //ctor
    //La carga de texturas podria ser otra clase


    //ctor
    pState= new PhysicsState();
    pState->setActualState(150,250);
    /**Funcionamiento: le digo la ruta de la textura y el numero de animaciones**/
    enemigo_sprite= new SuperSprite("assets/enemigo/ufo.png",4,0.6,true);
    enemigo_sprite->setSpeed(0.1);
    enemigo_sprite->addFrame(sf::IntRect(5, 7,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(52, 7,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(99, 7,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(146, 7,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(192, 7,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(238, 7,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(284, 7,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(330, 7,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(5, 49,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(52, 49,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(99, 49,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(146, 49,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(192, 49,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(238, 49,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(284, 49,44, 38),0);
    enemigo_sprite->addFrame(sf::IntRect(330, 49,44, 38),0);

    enemigo_sprite->addFrame(sf::IntRect(5, 7,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(52, 89,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(99, 7,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(146, 89,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(192, 7,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(238, 89,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(284, 7,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(330, 89,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(5, 49,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(52, 131,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(99, 89,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(146, 131,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(192, 89,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(238, 131,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(284, 89,44, 38),1);
    enemigo_sprite->addFrame(sf::IntRect(330, 131,44, 38),1);

    enemigo_sprite->addFrame(sf::IntRect(5, 89,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(52, 89,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(99, 89,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(146, 89,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(192, 89,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(238, 89,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(284, 89,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(330, 89,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(5, 131,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(52, 131,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(99, 131,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(146, 131,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(192, 131,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(238, 131,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(284, 131,44, 38),2);
    enemigo_sprite->addFrame(sf::IntRect(330, 131,44, 38),2);






    /**COSAS ENEMIGO**/
    pState->MoveTo(500,500);
    actitud = 0;
    teataco = 0;
    tiempo_espera = 1;
    tiempo_ataque = 1;
    tiempo_alerta = 1;
    tiempo_persecucion =5;
    direccion_patrullaje = 0;
    direccion_patrullaje2 = 0;


}

PhysicsState* Enemigo::getPhysicsState()
{
    return pState;
}

void Enemigo::setVision(bool v)
{
    teveo=v;
}
void Enemigo::setAtaque(bool v)
{
    teataco=v;
}
void Enemigo::setActitud(int a)
{
    actitud=a;
}

void Enemigo::updateEnemigo(double velx, double vely, sf::Time et)
{

    double x=0.0,y=0.0,power=20;

    switch (actitud)
    {
    case 0:

        enemigo_sprite->setAnimation(0);
        if(movingclock.getElapsedTime().asSeconds()>=tiempo_espera)
        {
            direccion_patrullaje= rand() % 5;
            direccion_patrullaje2= rand() % 5;

            tiempo_espera= rand() % 2 + 1;
            movingclock.restart();

            if(teveo==true)
            {
                alertclock.restart();
                cout<<"Estaba patruyando y le vi"<<endl;
                actitud=1;
            }
        }
        switch(direccion_patrullaje)
        {
        case 1:
            x+=-power;
            break;
        case 2:
            x+=power;
            break;
        case 3:
            y+=-power;
            break;
        case 4:
            y+=power;
            break;
        }
        switch(direccion_patrullaje2)
        {
        case 1:
            x+=-power;
            break;
        case 2:
            x+=power;
            break;
        case 3:
            y+=-power;
            break;
        case 4:
            y+=power;
            break;
        }
        break;

    case 1:


        enemigo_sprite->setAnimation(1);
        if(alertclock.getElapsedTime().asSeconds()>=tiempo_alerta)
        {
            if(teveo==true){
                actitud=2;
                chaseclock.restart();
            }
        }

    break;

case 2:

    enemigo_sprite->setAnimation(2);
    if (velx> pState->getActualState()[0])
    {
        x+=power;
    }
    else if (velx< pState->getActualState()[0])
    {
        x+=-power;
    }
    if(vely>pState->getActualState()[1])
    {
        y+=power;
    }
    else if(vely < pState->getActualState()[1])
    {
        y+=-power;
    }

    if(atackClock.getElapsedTime().asSeconds()>tiempo_ataque){
        atackClock.restart();
        teataco=true;
    }else{
        teataco=false;
    }

    break;

}


if(chaseclock.getElapsedTime().asSeconds()>=tiempo_persecucion)
{

    if(teveo==false){
        actitud=0;
    }else{
    chaseclock.restart();
    }

}

if(pState->getActualState()[0]>960)
x-=power;

if(pState->getActualState()[0]<0)
x+=power;

if(pState->getActualState()[1]>960)
y-=power;

if(pState->getActualState()[1]<0)
y+=power;


pState->Move(x,y,true);
pState->updatePhysicsState(et);

}

void Enemigo::calcInter(sf::RenderWindow *w, double i)
{

    /** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    this->enemigo_sprite->calcInter(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);

}

void Enemigo::drawEnemigo(sf::RenderWindow *w, double i)
{

    this->enemigo_sprite->drawSuperSprite(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);

}

Enemigo::~Enemigo()
{
    //dtor
}


