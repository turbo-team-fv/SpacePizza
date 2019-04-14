#include "Juego.h"

using namespace sf;

/** GLOBAL **/
const sf::Time Juego::timePerFrame = sf::milliseconds(1000.0/25.0);
/** GLOBAL **/

Juego::Juego()
{

    int resol_x=800;
    int resol_y=600;
    string gamename="Space Pizza";

    ventana = new RenderWindow(VideoMode(resol_x,resol_y),gamename);
    ventana->setVerticalSyncEnabled(true); //Para evitar cortes en los refrescos
    //ventana->setFramerateLimit(25);

    menu = EMenu::getInstance();

    /**Eventos**/
    eUp=false;
    eDown=false;
    eLeft=false;
    eRight=false;
    /**Eventos**/

    mundo = new Mundo();
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

        // Control del tiempo de juego
        //if(gameClock.getElapsedTime().asSeconds() < mundo->getTime()) {
            //Proceso mis eventos

            handleEvents();


            if(updateClock.getElapsedTime().asMilliseconds()>timePerFrame.asMilliseconds()) {
                //Calculamos el tiempo desde el ultimo update
                elapsedTime=updateClock.restart();

                //updateamos dependiendo del tiempo pasado
                updateGameState( eRight, eLeft, eUp, eDown, elapsedTime);
            }

            // Se calcula el porcentaje de interpolacion
            // interpolation = std::min(1.0,(double)updateClock.getElapsedTime().asMilliseconds() / (double)timePerFrame.asMilliseconds());

        render(interpolation);

        //}else {
            /// TODO: Cambiar de estado en vez de hacer exit
            //exit(0);
        //}


    }

}

/**Aqui leemos el tipo de evento recibido desde fuera**/
void Juego::handleEvents()
{

    Event event;
    if (ventana->pollEvent(event))
    {

        switch (event.type)
        {
        case Event::KeyPressed:

            handleInputs(event.key.code, true);
            break;

        case Event::KeyReleased:

            handleInputs(event.key.code, false);
            break;

        case Event::Closed:
            ventana->close();
            break;
        }
    }

}
/** Interruptor de Input que actua segun lo recibido del handle events**/
void Juego::handleInputs(sf::Keyboard::Key key, bool isPressed)
{

    if (key == sf::Keyboard::Up)
    {
        //Traslaciones
        eUp = isPressed;

////        if(eUp)
////            menu->MoveUp();

    }
    if (key == sf::Keyboard::Down)
    {
        eDown = isPressed;

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


/**Update de juego donde se actualiza TODO **/
void Juego::updateGameState(bool eRight,bool eLeft,bool eUp,bool eDown,sf::Time t)
{

    /**Y aqui Updateariamos lo que tengamos que updatear, ejemplo
    **/
    mundo->updateMundo(eRight,eLeft,eUp,eDown,t);
}

void Juego::updateTime(int change) {
//    tiempoJuego += change;
}

/**Metodo para administrar el renderizado que recibe la interpolacion**/
void Juego::render(double i)
{

    ventana->clear();
    interpolation = std::min(1.0,(double)updateClock.getElapsedTime().asMilliseconds() / (double)timePerFrame.asMilliseconds());
    mundo->drawMundo(ventana,interpolation);

    ventana->display();
}



