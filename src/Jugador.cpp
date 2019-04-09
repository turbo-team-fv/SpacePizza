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
}

PhysicsState Jugador::getPhysicsState()
{
    return pState;
}


void Jugador::updateJugador(double velx, double vely, sf::Time et)
{

    pState.Move(velx,vely,true);//Cambia el booleano para quitar aceleracion o ponerla
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

Jugador::~Jugador()
{
    //dtor
}
