#include "Juego.h"
#include "EJugando.h"
#include "EMenu.h"

using namespace sf;

/** GLOBAL **/
const sf::Time Juego::timePerFrame = sf::milliseconds(1000.0/25.0);
/** GLOBAL **/

Juego::Juego()
{

    int resol_x=800;
    int resol_y=600;
    string gamename="Space Pizza";

//    ventana = new RenderWindow(VideoMode(resol_x,resol_y), gamename, sf::Style::Fullscreen);
    ventana = new RenderWindow(VideoMode(resol_x,resol_y), gamename);

    ventana->setVerticalSyncEnabled(true); //Para evitar cortes en los refrescos
    //ventana->setFramerateLimit(25);

    estadoActivo = EMenu::getInstance();
}

Juego::~Juego()
{
    //dtor
}

Juego* Juego::jInstancia = 0;

Juego* Juego::getInstance()
{
    if(jInstancia==0)
    {
        jInstancia = new Juego();
    }

    return jInstancia;
}

/**Loop de juego donde ocurre todo**/
void Juego::loop()
{
    // NEW
    while(ventana->isOpen())
    {
        estadoActivo->loop(ventana, timePerFrame);
    }

}

void Juego::cambiarEstado(State* state)
{
    estadoActivo = state;
}
