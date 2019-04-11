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
    spri.setTextureRect(sf::IntRect(5, 7,44, 38));
    spri.scale(1,1);

    renderPos.push_back(0.0);
    renderPos.push_back(0.0);

    /**COSAS ENEMIGO**/
    pState.MoveTo(500,500);
    actitud = 0;
    tiempo_espera = 3;
    direccion_patrullaje = 0;
    direccion_patrullaje2 = 0;


}

PhysicsState Enemigo::getPhysicsState()
{
    return pState;
}


void Enemigo::updateEnemigo(double velx, double vely, sf::Time et)
{

    double x=0.0,y=0.0,power=20;

    if(actitudTest.getElapsedTime().asSeconds()>=5)
        {
         actitud= rand () % 3;
         actitudTest.restart();
        }

    switch (actitud)
    {
    case 0:

    spri.setTextureRect(sf::IntRect(5, 7,44, 38));
        if(movingclock.getElapsedTime().asSeconds()>=tiempo_espera)
        {
            direccion_patrullaje= rand() % 5;
            direccion_patrullaje2= rand() % 5;

            tiempo_espera= rand() % 1 + 1;
            movingclock.restart();
            cout<<"El enemigo esta patrullando"<<endl;
            cout<<"Direccion es: "<<direccion_patrullaje<<endl;
            cout<<"Direccion adicional es: "<<direccion_patrullaje2<<endl;
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


    spri.setTextureRect(sf::IntRect(5, 89,44, 38));
     if(movingclock.getElapsedTime().asSeconds()>=tiempo_espera)
        {

            tiempo_espera=0.5;
            movingclock.restart();
            cout<<"El enemigo esta alerta"<<endl;


        spri.setTextureRect(sf::IntRect(5, 7,44, 38));
        }






        break;

    case 2:

        //move the nerd towards the player
        cout<<"CORRE"<<endl;
        spri.setTextureRect(sf::IntRect(5, 89,44, 38));
        if (velx> pState.getActualState()[0])
        {
            x+=power;
        }
        else if (velx< pState.getActualState()[0])
        {
            x+=-power;
        }
        if(vely>pState.getActualState()[1])
        {
            y+=power;
        }
        else if(vely < pState.getActualState()[1])
        {
            y+=-power;
        }

        break;

    }




    pState.Move(x,y,true);
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


