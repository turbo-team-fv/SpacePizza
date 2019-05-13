#include "Enemigo.h"

Enemigo::Enemigo()
{

    pState=new PhysicsState();

    //ctor
    pState= new PhysicsState();
    pState->setActualState(sf::Vector2f(150,250));

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


    alert_id=0;
    Popup *pop=new Popup("assets/hud/popups/dialogos.png",2);
    pop->getSprite()->addFrame(sf::IntRect(5,1,97,54),0);
    alert.push_back(pop);

    pop=new Popup("assets/hud/popups/dialogos.png",2);
    pop->getSprite()->addFrame(sf::IntRect(106,7,97,54),0);
    alert.push_back(pop);

    pop=new Popup("assets/hud/popups/dialogos.png",2);
    pop->getSprite()->addFrame(sf::IntRect(5,58,89,49),0);
    alert.push_back(pop);

    pop=new Popup("assets/hud/popups/dialogos.png",2);
    pop->getSprite()->addFrame(sf::IntRect(106,58,95,49),0);
    alert.push_back(pop);



    /**COSAS ENEMIGO**/
    pState->MoveTo(sf::Vector2f(500,500));
    actitud = 0;
    teataco = 0;
    tiempo_espera = 1;
    tiempo_ataque = 1;
    tiempo_alerta = 1;
    tiempo_persecucion =5;
    direccion_patrullaje = 0;
    direccion_patrullaje2 = 0;

    /**SONIDO**/
    bufferAlien = new sf::SoundBuffer();
    bufferAlien->loadFromFile("assets/sonidos/alien.ogg");
    soundAlien = new sf::Sound();
    soundAlien->setBuffer(*bufferAlien);
    soundAlien->setLoop(true);
    soundAlien->setVolume(200);
    soundAlien->setPitch(1.3);
    soundAlien->play();
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

void Enemigo::updateEnemigo(sf::Vector2f vel, sf::Time et)
{
    sf::Vector2f incremento;
    float power=20;

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
            incremento.x+=-power;
            break;
        case 2:
            incremento.x+=power;
            break;
        case 3:
            incremento.y+=-power;
            break;
        case 4:
            incremento.y+=power;
            break;
        }
        switch(direccion_patrullaje2)
        {
        case 1:
            incremento.x+=-power;
            break;
        case 2:
            incremento.x+=power;
            break;
        case 3:
            incremento.y+=-power;
            break;
        case 4:
            incremento.y+=power;
            break;
        }
        break;

    case 1:


        enemigo_sprite->setAnimation(1);
        if(alertclock.getElapsedTime().asSeconds()>=tiempo_alerta)
        {
            if(teveo==true){

                alert_id=(rand()%3 + 1);
                alert[alert_id]->throwPopup();
                actitud=2;

                chaseclock.restart();
            }
        }

    break;

case 2:

    enemigo_sprite->setAnimation(2);
    if (vel.x> pState->getActualState().x)
    {
        incremento.x+=power;
    }
    else if (vel.x< pState->getActualState().x)
    {
        incremento.x+=-power;
    }
    if(vel.y>pState->getActualState().y)
    {
       incremento.y+=power;
    }
    else if(vel.y < pState->getActualState().y)
    {
        incremento.y+=-power;
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

if(pState->getActualState().x>960)
incremento.x-=power;

if(pState->getActualState().x<0)
incremento.x+=power;

if(pState->getActualState().y>960)
incremento.y-=power;

if(pState->getActualState().y<0)
incremento.y+=power;


pState->Move(incremento,true);
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
    alert[alert_id]->setPosition(sf::Vector2f(enemigo_sprite->getRenderPos().x-20,enemigo_sprite->getRenderPos().y-20));
    alert[alert_id]->drawPopup(w,i);

}

void Enemigo::setVolumen(float v)
{
    this->soundAlien->setVolume(v);
}

Enemigo::~Enemigo()
{
    //dtor
}


