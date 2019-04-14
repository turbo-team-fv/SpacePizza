#include "Jugador.h"

Jugador::Jugador(): pState() /**Asi inicializamos de mejor forma objetos que son intrinsecos del padre**/
{
    //ctor
    //La carga de texturas podria ser otra clase
    tex.loadFromFile("assets/jugador/sp_alien_texture.png");
    if (!tex.loadFromFile("assets/jugador/sp_alien_texture.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }

    spri.setTexture(tex);
    spri.setOrigin(28/2,44/2);
    spri.setTextureRect(sf::IntRect(50, 52,40, 44));
    spri.scale(1,1);

    renderPos.push_back(0.0);
    renderPos.push_back(0.0);

    vidas = 5;
}

PhysicsState Jugador::getPhysicsState()
{
    return pState;
}


void Jugador::updateJugador(bool eRight,bool eLeft,bool eUp,bool eDown, sf::Time et)
{

    double x=0,y=0,potencia=50;

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
    renderPos[0]=(getPhysicsState().getActualState()[0]-getPhysicsState().getPastState()[0])*i+getPhysicsState().getPastState()[0];
    renderPos[1]=(getPhysicsState().getActualState()[1]-getPhysicsState().getPastState()[1])*i+getPhysicsState().getPastState()[1];

    spri.setPosition(renderPos[0], renderPos[1]);
    w->draw(spri);
}

// Este metodo permite modifcar la vida => hay que pasarle el valor a modificar incluyendo el signo si queremos restar
void Jugador::updateVida(int change) {
    vidas = vidas + change;
    if(vidas < 0) {
        vidas = 0;
    }
    if(vidas >= 5 ) {
        vidas = 5;
    }
    std::cout<<"Muestor la vida despues de la operacion: "<< vidas<<std::endl;
}

Jugador::~Jugador()
{
    //dtor
}
