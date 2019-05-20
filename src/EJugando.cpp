#include "EJugando.h"

EJugando::EJugando()
{
    //ctor

    this->Init();

}

EJugando* EJugando::eJugandoInstancia = 0;

EJugando* EJugando::getInstance()
{
    if(eJugandoInstancia == 0)
    {
        eJugandoInstancia = new EJugando();
    }
    return eJugandoInstancia;
}


void EJugando::Init()
{

    /**Eventos**/
    Puntuacion::getInstance()->resetPuntuacion();
    eUp=false;
    eDown=false;
    eLeft=false;
    eRight=false;
    godMode=false;
    /**Eventos**/

    /// inicializa un mundo (contiene todos los objetos del juego)
    mundo = new Mundo();


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

        updateGameState( eRight, eLeft, eUp, eDown, godMode, elapsedTime);
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

void EJugando::updateGameState(bool eRight,bool eLeft,bool eUp,bool eDown, bool godMod,sf::Time t)
{
    mundo->updateMundo(eRight,eLeft,eUp,eDown,godMode,t);
}

void EJugando::render(double i, RenderWindow * ventana, Time timePerFrame)
{
    ventana->clear();
    interpolation = std::min(1.0,(double)updateClock.getElapsedTime().asMilliseconds() / (double)timePerFrame.asMilliseconds());
    mundo->drawMundo(ventana,interpolation);

    ventana->display();
}



void EJugando::HandleInputs(sf::Keyboard::Key key, bool isPressed)
{
    switch(key)
    {
    case sf::Keyboard::Up :
        eUp = isPressed;
        break;

    case sf::Keyboard::Down :
        eDown = isPressed;
        break;

    case sf::Keyboard::Left :
        eLeft = isPressed;
        break;

    case sf::Keyboard::Right :
        eRight = isPressed;
        break;
    case sf::Keyboard::G :

        if(!isPressed){
            if(godMode){
                godMode = false;

            }else{
                godMode = true;

            }
            }


        break;


    /**SELECCION DE RADIOS**/
    case sf::Keyboard::Num1 :
        ControladorSonido::getInstance()->playRadio(0);
        break;

    case sf::Keyboard::Num2 :
        ControladorSonido::getInstance()->playRadio(1);
        break;

    case sf::Keyboard::Num3 :
        ControladorSonido::getInstance()->playRadio(2);
        break;

    case sf::Keyboard::Num4 :
        ControladorSonido::getInstance()->playRadio(3);
        break;

    }
}
void EJugando::Update()
{

}
void EJugando::Draw(RenderWindow * ventana)
{

}

