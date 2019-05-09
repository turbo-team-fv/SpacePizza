#include "Jugador.h"

Jugador::Jugador() /**Asi inicializamos de mejor forma objetos que son intrinsecos del padre**/
{
    pState=new PhysicsState();
    //ctor
    pState= new PhysicsState();
    pState->setActualState(150,250);
    /**Funcionamiento: le digo la ruta de la textura y el numero de animaciones**/
    jugador_sprite= new SuperSprite("assets/jugador/sp_alien_texture.png",4,0.4,true);
    turbo= new SuperSprite("assets/jugador/turbo.png",4,0.6,true);

    turbo->addFrame(sf::IntRect(27, 11,27, 58),0);
    turbo->addFrame(sf::IntRect(84, 17,31, 48),0);
    turbo->addFrame(sf::IntRect(147, 14,35, 54),0);
    turbo->addFrame(sf::IntRect(209, 12,35, 56),0);
    turbo->addFrame(sf::IntRect(27, 82,27, 58),1);
    turbo->addFrame(sf::IntRect(83, 85,31, 48),1);
    turbo->addFrame(sf::IntRect(138, 80,35, 54),1);
    turbo->addFrame(sf::IntRect(199, 79,35, 56),1);
    turbo->addFrame(sf::IntRect(11, 147,55, 27),2);
    turbo->addFrame(sf::IntRect(74, 147,48, 31),2);
    turbo->addFrame(sf::IntRect(128, 147,54, 35),2);
    turbo->addFrame(sf::IntRect(188, 147,56, 35),2);
    turbo->addFrame(sf::IntRect(11, 201,55, 27),3);
    turbo->addFrame(sf::IntRect(74, 197,48, 31),3);
    turbo->addFrame(sf::IntRect(128, 193,54, 35),3);
    turbo->addFrame(sf::IntRect(188, 193,56, 35),3);

    turbo->setSpeed(0.1);

    invisible= new SuperSprite("assets/jugador/invisible.png",1,0.6,true);

    invisible->addFrame(sf::IntRect(127, 4,43, 42),0);
    invisible->addFrame(sf::IntRect(172, 3,45, 44),0);
    invisible->addFrame(sf::IntRect(219, 1,47, 47),0);
    invisible->addFrame(sf::IntRect(268, 1,49, 49),0);
     invisible->addFrame(sf::IntRect(219, 1,47, 47),0);
      invisible->addFrame(sf::IntRect(172, 3,45, 44),0);
      invisible->addFrame(sf::IntRect(127, 4,43, 42),0);


    invisible->setSpeed(0.1);

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
    colinit.push_back(sf::FloatRect(-6,10,10,6));//ab
    colinit.push_back(sf::FloatRect(-15,0,6,8));//iz
    colinit.push_back(sf::FloatRect(15,0,-6,8));//der
    colinit.push_back(sf::FloatRect(-6,-0,10,-8));//arr
    pState->setColliders(colinit);


    vidas = 5;
    limite_estado=5;
}

PhysicsState* Jugador::getPhysicsState()
{
    return pState;
}

void Jugador::restartEstado()
{

    timer_estado.restart();

}
void Jugador::updateJugador(bool eRight,bool eLeft,bool eUp,bool eDown,sf::Vector2f bounce, sf::Time et)
{

    double x=0,y=0,potencia=50;

    if(bounce.x<0){
    eRight=false;
    eLeft=true;
    }
    if(bounce.x>0){
    eLeft=false;
    eRight=true;
    }
    if(bounce.y<0){
    eDown=false;
    eUp=true;
    }
    if(bounce.y>0){
    eUp=false;
    eDown=true;
}
    if(estado==1)
    {
       // cout<<"TURBO"<<endl;
        potencia=potencia*2;
        jugador_sprite->setSpeed(0.1);
    }
    else
    {
        jugador_sprite->setSpeed(0.2);
    }



    if(eRight)
    {
        jugador_sprite->setAnimation(1);
        turbo->setAnimation(1);
        //La tecla Derecha está pulsada:
        x=potencia;

    }
    if(eLeft)
    {
        jugador_sprite->setAnimation(0);
        turbo->setAnimation(0);
        x=-potencia;
        //La tecla Izquierda está pulsada:
    }
    if(eUp)
    {
        turbo->setAnimation(2);
        jugador_sprite->setAnimation(2);
        y=-potencia;
        //La tecla Arriba está pulsada:
    }
    if(eDown)
    {
        jugador_sprite->setAnimation(3);
        turbo->setAnimation(3);
        y=potencia;
        //La tecla Abajo está pulsada:
    }

    if(timer_estado.getElapsedTime().asSeconds()>=limite_estado)
    {
        estado=0;
    }

    if(cesped&&(abs(pState->getVel()[0])>50||abs(pState->getVel()[1])>50)){
    x=0;
    y=0;

    cout<<"Reacciona al cesped"<<endl;
    }

    pState->Move(x+bounce.x,y+bounce.y,true);//Cambia el booleano para quitar aceleracion o ponerla
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

    if(estado==1)
    {
        this->turbo->drawSuperSprite(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);
    }

    if(estado==2)
    {
        this->invisible->drawSuperSprite(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);
    }

}

int Jugador::checkEstado()
{

    return estado;

}

int Jugador::getVidas()
{
    return vidas;
}

void Jugador::setEstado(int e)
{

    estado=e;

}
void Jugador::setCesped(bool c){
cesped=c;
}
// Este metodo permite modifcar la vida => hay que pasarle el valor a modificar incluyendo el signo si queremos restar
void Jugador::updateVida(int change)
{
    vidas = vidas + change;
    if(vidas < 0)
    {
        vidas = 0;
    }
    if(vidas >= 5 )
    {
        vidas = 5;
    }
    std::cout<<"Muestor la vida despues de la operacion: "<< vidas<<std::endl;
}

Jugador::~Jugador()
{
    //dtor
}
