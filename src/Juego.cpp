#include "Juego.h"


/** GLOBAL **/
const sf::Time Juego::timePerFrame = sf::milliseconds(1000.0/25.0);
/** GLOBAL **/

Juego::Juego()
{

    int resol_x=800;
    int resol_y=600;
    string gamename="Space Pizza";

    ventana= new sf::RenderWindow(sf::VideoMode(resol_x,resol_y),gamename);
    ventana->setVerticalSyncEnabled(true); //Para evitar cortes en los refrescos

    /**Eventos**/
    eUp=false;
    eDown=false;
    eLeft=false;
    eRight=false;
    /**Eventos**/

    mapa = new Mapa();


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

    while (ventana->isOpen())
    {


        //Proceso mis eventos

        handleEvents();


        if(updateClock.getElapsedTime().asMilliseconds()>timePerFrame.asMilliseconds())
        {
            //Calculamos el tiempo desde el ultimo update
            elapsedTime=updateClock.restart();

            //updateamos dependiendo del tiempo pasado
            updateGameState(elapsedTime);
        }

        //Se calcula el porcentaje de interpolacion
        interpolation = std::min(1.0,(double)updateClock.getElapsedTime().asMilliseconds() / (double)timePerFrame.asMilliseconds());

        //Renderizamos con interpolacion
        render(interpolation);


    }

}

/**Aqui leemos el tipo de evento recibido desde fuera**/
void Juego::handleEvents()
{

    sf::Event event;
    if (ventana->pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::KeyPressed:

            handleInputs(event.key.code, true);
            break;

        case sf::Event::KeyReleased:

            handleInputs(event.key.code, false);
            break;

        case sf::Event::Closed:
            ventana->close();
            break;
        }
    }

}
/** Interruptor de Input que actua segun lo recibido del handle events**/
void Juego::handleInputs(sf::Keyboard::Key key, bool isPressed)
{

    if (key == sf::Keyboard::Up)            //Traslaciones
        eUp = isPressed;
    else if (key == sf::Keyboard::Down)
        eDown = isPressed;
    else if (key == sf::Keyboard::Left)
        eLeft = isPressed;
    else if (key == sf::Keyboard::Right)
        eRight = isPressed;

}

/**Update de juego donde se actualiza TODO **/
void Juego::updateGameState(sf::Time t)
{

    if(eRight)
    {
        //La tecla Derecha está pulsada:
    }
    else if(eLeft)
    {
        //La tecla Izquierda está pulsada:
    }
    else if(eUp)
    {
        //La tecla Arriba está pulsada:
    }
    else if(eDown)
    {
        //La tecla Abajo está pulsada:
    }

    /**Y aqui Updateariamos lo que tengamos que updatear, ejemplo

    player.UpdatePlayer (velx,vely,t)

    **/

}

/**Metodo para administrar el renderizado que recibe la interpolacion**/
void Juego::render(double i)
{
    ventana->clear();
    //
    //Dibujamos nuestras mierdas
    mapa->draw(ventana);
    //
    ventana->display();
}

