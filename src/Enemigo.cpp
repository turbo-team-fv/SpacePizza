#include "Enemigo.h"

Enemigo::Enemigo():pState()
{
    //ctor
    //La carga de texturas podria ser otra clase
    tex.loadFromFile("assets/enemigo/ufo.png");
    if (!tex.loadFromFile("assets/enemigo/ufo.png"))
    {
        std::cerr << "Error cargando la imagen ufo.png";
        exit(0);
    }

    spri.setTexture(tex);
    spri.setOrigin(28/2,44/2);
    spri.setTextureRect(sf::IntRect(50, 52,40, 44));
    spri.scale(1,1);

    renderPos.push_back(0.0);
    renderPos.push_back(0.0);
}

PhysicsState Enemigo::getPhysicsState()
{
    return pState;
}


void Enemigo::updateEnemigo(double velx, double vely, sf::Time et)
{

    double x=0.0,y=0.0;

    //move the nerd towards the player
    if (velx> pState.getActualState()[0])
    {
        x+=35.0,y+=0.0;
    }
    else if (velx< pState.getActualState()[0])
    {
        x+=-35.0,y+=0.0;
    }
    if(vely>pState.getActualState()[1])
    {
        y+=35.0,x+=0.0;
    }
    else if(vely < pState.getActualState()[1])
    {
        y+=-35.0,x+=0.0;
    }
    pState.Move(x,y,true);

    cout<<"Desplaza en x: "<<x<<endl;
    cout<<"Desplaza en y: "<<y<<endl;




    pState.updatePhysicsState(et);

}


void Enemigo::drawEnemigo(sf::RenderWindow *w, double i)
{

    /** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    renderPos[0]=(getPhysicsState().getActualState()[0]-getPhysicsState().getPastState()[0])*i+getPhysicsState().getPastState()[0];
    renderPos[1]=(getPhysicsState().getActualState()[1]-getPhysicsState().getPastState()[1])*i+getPhysicsState().getPastState()[1];

    spri.setPosition(renderPos[0], renderPos[1]);
    w->draw(spri);
}

Enemigo::~Enemigo()
{
    //dtor
}


