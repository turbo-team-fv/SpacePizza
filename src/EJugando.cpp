#include "EJugando.h"

EJugando::EJugando()
{
    //ctor

    /**Eventos**/
    eUp=false;
    eDown=false;
    eLeft=false;
    eRight=false;
    /**Eventos**/

    /// inicializa un mundo (contiene todos los objetos del juego)
    mundo = new Mundo();
}

EJugando* EJugando::eJugandoInstancia = 0;

EJugando* EJugando::getInstance()
{
    if(eJugandoInstancia == 0)
    {
        eJugandoInstancia = new EJugando();
    }
    //return eJugandoInstancia;
}

void EJugando::loop(RenderWindow * ventana, Time timePerFrame)
{
    //Proceso mis eventos
    HandleEvents(ventana);


    if(updateClock.getElapsedTime().asMilliseconds()>timePerFrame.asMilliseconds())
    {
        //Calculamos el tiempo desde el ultimo update
        elapsedTime=updateClock.restart();

        //updateamos dependiendo del tiempo pasado
        updateGameState( eRight, eLeft, eUp, eDown, elapsedTime);
    }

    //Se calcula el porcentaje de interpolacion
    //interpolation = std::min(1.0,(double)updateClock.getElapsedTime().asMilliseconds() / (double)timePerFrame.asMilliseconds());

    //Renderizamos con interpolacion
    render(interpolation, ventana, timePerFrame);

}

void EJugando::HandleEvents(RenderWindow * ventana)
{
    Event event;
    if (ventana->pollEvent(event))
    {
        switch (event.type)
        {
        case Event::KeyPressed:

            HandleInputs(event.key.code, true);
            break;

        case Event::KeyReleased:

            HandleInputs(event.key.code, false);
            break;

        case Event::Closed:
            ventana->close();
            break;
        }
    }
}

void EJugando::updateGameState(bool eRight,bool eLeft,bool eUp,bool eDown,sf::Time t)
{
    mundo->updateMundo(eRight,eLeft,eUp,eDown,t);
}

void EJugando::render(double i, RenderWindow * ventana, Time timePerFrame)
{
    ventana->clear();
    interpolation = std::min(1.0,(double)updateClock.getElapsedTime().asMilliseconds() / (double)timePerFrame.asMilliseconds());
    mundo->drawMundo(ventana,interpolation);

    ventana->display();
}


void EJugando::Init()
{

}

void EJugando::HandleInputs(sf::Keyboard::Key key, bool isPressed)
{
        if (key == sf::Keyboard::Up)
    {
        //Traslaciones
        eUp = isPressed;
        std::cout<<"Se ha pulsado Up"<<std::endl;
////        if(eUp)
////            menu->MoveUp();

    }
    if (key == sf::Keyboard::Down)
    {
        eDown = isPressed;
        std::cout<<"Se ha pulsado Down"<<std::endl;
////        if(eDown)
////            menu->MoveDown();
    }

    if (key == sf::Keyboard::Left )
    {
        eLeft = isPressed;
    }

    if (key == sf::Keyboard::Right)
    {
        eRight = isPressed;
    }
    if (key == sf::Keyboard::Return )
    {

        /*switch(menu->getSelectedItem()){
            case 0:
                std::cout<<"Se ha seleccionado Play"<<std::endl;
                break;
            case 1:
                std::cout<<"Se ha seleccionado Options"<<std::endl;
                break;
            case 2:
                std::cout<<"Se ha seleccionado Exit"<<std::endl;
                ventana->close();
                break;
        }*/
    }
}
void EJugando::Update()
{

}
void EJugando::Draw(RenderWindow * ventana)
{

}

