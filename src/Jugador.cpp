#include "Jugador.h"
#include "Puntuacion.h"

Jugador::Jugador() /**Asi inicializamos de mejor forma objetos que son intrinsecos del padre**/
{

    pState= new PhysicsState();
    pState->setActualState(sf::Vector2f(250,450));

    /**Funcionamiento: le digo la ruta de la textura y el numero de animaciones**/
    fake= new SuperSprite("assets/jugador/playercamo.png",4,0.6,true);
    fake->setSpeed(0.1);
     fake->addFrame(sf::IntRect(5, 89,44, 38),0);
    fake->addFrame(sf::IntRect(52, 89,44, 38),0);
    fake->addFrame(sf::IntRect(99, 89,44, 38),0);
    fake->addFrame(sf::IntRect(146, 89,44, 38),0);
    fake->addFrame(sf::IntRect(192, 89,44, 38),0);
    fake->addFrame(sf::IntRect(238, 89,44, 38),0);
    fake->addFrame(sf::IntRect(284, 89,44, 38),0);
    fake->addFrame(sf::IntRect(330, 89,44, 38),0);
    fake->addFrame(sf::IntRect(5, 131,44, 38),0);
    fake->addFrame(sf::IntRect(52, 131,44, 38),0);
    fake->addFrame(sf::IntRect(99, 131,44, 38),0);
    fake->addFrame(sf::IntRect(146, 131,44, 38),0);
    fake->addFrame(sf::IntRect(192, 131,44, 38),0);
    fake->addFrame(sf::IntRect(238, 131,44, 38),0);
    fake->addFrame(sf::IntRect(284, 131,44, 38),0);
    fake->addFrame(sf::IntRect(330, 131,44, 38),0);

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

    escudo= new SuperSprite("assets/jugador/invisible.png",1,0.6,true);

    escudo->addFrame(sf::IntRect(127, 4,43, 42),0);
    escudo->addFrame(sf::IntRect(172, 3,45, 44),0);
    escudo->addFrame(sf::IntRect(219, 1,47, 47),0);
    escudo->addFrame(sf::IntRect(268, 1,49, 49),0);
    escudo->addFrame(sf::IntRect(219, 1,47, 47),0);
    escudo->addFrame(sf::IntRect(172, 3,45, 44),0);
    escudo->addFrame(sf::IntRect(127, 4,43, 42),0);
    escudo->setSpeed(0.1);

    bump= new Popup("assets/jugador/bump.png",0.2);
    bump->getSprite()->addFrame(sf::IntRect(26, 16,8, 8),0);
    bump->getSprite()->addFrame(sf::IntRect(82, 13,17, 16),0);
    bump->getSprite()->addFrame(sf::IntRect(141, 11,22, 22),0);
    bump->getSprite()->addFrame(sf::IntRect(197, 7,30, 30),0);
    bump->getSprite()->addFrame(sf::IntRect(253, 5,38, 34),0);

    camuflaje= new SuperSprite("assets/jugador/invisible.png",1,0.6,true);

    camuflaje->addFrame(sf::IntRect(26, 16,8, 8),0);
    camuflaje->addFrame(sf::IntRect(82, 13,17, 16),0);
    camuflaje->addFrame(sf::IntRect(141, 11,22, 22),0);
    camuflaje->addFrame(sf::IntRect(197, 7,30, 30),0);
    camuflaje->addFrame(sf::IntRect(253, 5,38, 34),0);


    camuflaje->setSpeed(0.05);

    jugador_sprite->addFrame(sf::IntRect(50, 52,40, 44),0);//iz
    jugador_sprite->addFrame(sf::IntRect(2, 50,40, 46),0);

    jugador_sprite->addFrame(sf::IntRect(6, 98,40, 46),1);//der
    jugador_sprite->addFrame(sf::IntRect(54, 100,40, 44),1);

    jugador_sprite->addFrame(sf::IntRect(8, 146,32, 46),2);//arr
    jugador_sprite->addFrame(sf::IntRect(56, 148,32, 44),2);

    jugador_sprite->addFrame(sf::IntRect(10, 4,28, 44),3);//ab
    jugador_sprite->addFrame(sf::IntRect(58, 6,28, 42),3);

    muerte= new Popup("assets/jugador/player_death.png",0.5);
    muerte->getSprite()->addFrame(sf::IntRect(20,18,75,77),0);
    muerte->getSprite()->addFrame(sf::IntRect(141,10,95,108),0);
    muerte->getSprite()->addFrame(sf::IntRect(264,2,107,121),0);
    muerte->getSprite()->addFrame(sf::IntRect(392,5,113,118),0);
    muerte->getSprite()->addFrame(sf::IntRect(10,133,108,115),0);
    muerte->getSprite()->addFrame(sf::IntRect(141,133,100,115),0);
    muerte->getSprite()->addFrame(sf::IntRect(269,141,95,95),0);
    muerte->getSprite()->addFrame(sf::IntRect(397,146,95,87),0);
    muerte->getSprite()->addFrame(sf::IntRect(18,274,84,87),0);
    muerte->getSprite()->addFrame(sf::IntRect(164,294,48,54),0);
    muerte->getSprite()->addFrame(sf::IntRect(292,294,48,52),0);
    muerte->getSprite()->addFrame(sf::IntRect(420,297,46,49),0);

    /**COLLIDERS**/
    vector <sf::Rect<float> > colinit;
    colinit.push_back(sf::FloatRect(-6,5,10,6));//ab
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

    sf::Vector2f incremento;
    float potencia=35;

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
        incremento.x=potencia;

    }
    if(eLeft)
    {
        jugador_sprite->setAnimation(0);
        turbo->setAnimation(0);
        incremento.x=-potencia;
        //La tecla Izquierda está pulsada:
    }
    if(eUp)
    {
        turbo->setAnimation(2);
        jugador_sprite->setAnimation(2);
        incremento.y=-potencia;
        //La tecla Arriba está pulsada:
    }
    if(eDown)
    {
        jugador_sprite->setAnimation(3);
        turbo->setAnimation(3);
        incremento.y=potencia;
        //La tecla Abajo está pulsada:
    }

    if(timer_estado.getElapsedTime().asSeconds()>=limite_estado&&estado!=10)
    {
        estado=0;
    }

    if(bounce.x<0)
    {
        incremento.x=-potencia*2;
        bump->throwPopup();
    }
    else if(bounce.x>0)
    {
        incremento.x=potencia*2;
        bump->throwPopup();
    }
    if(bounce.y<0)
    {
        incremento.y=-potencia*2;
        bump->throwPopup();
    }
    else if(bounce.y>0)
    {
        incremento.y=potencia*2;
        bump->throwPopup();
    }

    if(cesped&&(abs(pState->getVel().x)>50||abs(pState->getVel().y)>50))
    {
        incremento.x=0;
        incremento.y=0;
    }
    if(pState->getActualState().x>1215)
incremento.x-=potencia;

if(pState->getActualState().x<240)
incremento.x+=potencia;

if(pState->getActualState().y>1260)
incremento.y-=potencia;

if(pState->getActualState().y<165)
incremento.y+=potencia;
    if(estado!=10)
    {

        pState->Move(incremento,true);//Cambia el booleano para quitar aceleracion o ponerla
        pState->updatePhysicsState(et);
    }
    else
    {
        cout<<"muerto"<<endl;

        muerte->throwPopup();

//        ControladorSonido::getInstance()->playExplosion();
    }

}

void Jugador::calcInter(sf::RenderWindow *w, double i)
{
    /** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    this->jugador_sprite->calcInter(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);

}

void Jugador::drawJugador(sf::RenderWindow *w, double i)
{

    /** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    if(estado!=2)
    this->jugador_sprite->drawSuperSprite(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);
    else
    this->fake->drawSuperSprite(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);

    if(estado==1)
    {
        this->turbo->drawSuperSprite(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);
    }

    if(estado==3)
    {
        this->escudo->drawSuperSprite(this->getPhysicsState()->getPastState(),this->getPhysicsState()->getActualState(),w,i);
    }
    if(estado==10){
    muerte->setPosition(jugador_sprite->getRenderPos());

    muerte->drawPopup(w,i);
    }
    bump->setPosition(jugador_sprite->getRenderPos());
    bump->drawPopup(w,i);

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
void Jugador::setCesped(bool c)
{
    cesped=c;
}
// Este metodo permite modifcar la vida => hay que pasarle el valor a modificar incluyendo el signo si queremos restar
void Jugador::updateVida(int change)
{
    vidas = vidas + change;
    if(change<0)
    bump->throwPopup();

    if(vidas < 0)
    {
        vidas = 0;
        estado=10;

    }
    if(vidas >= 5 )
    {
        vidas = 5;
    }
}

Jugador::~Jugador()
{
    //dtor
}
