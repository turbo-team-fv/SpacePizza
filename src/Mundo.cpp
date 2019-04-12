#include "Mundo.h"

Mundo::Mundo()
{
    //ctor
    ptoEntrgaActual = 0;

    // Inicializo los puntos de entrega
    puntosEntrega.push_back(sf::Vector2f(150,150));
    puntosEntrega.push_back(sf::Vector2f(500,500));
    ptoEntrega = new sf::RectangleShape(sf::Vector2f(15.0,15.0));
    ptoEntrega->setFillColor(sf::Color::Blue);
    ptoEntrega->setPosition(puntosEntrega[0]);

    // Creo los PoweUPs
    Item *vida1 = new Item(1, sf::Vector2f(360,150), 2, 5);
    items.push_back(vida1);
    Item *tiempo1 = new Item(2, sf::Vector2f(420,425), 2,10);
    items.push_back(tiempo1);

    /**EELEMENTOS**/
    mapa = new Mapa();
    p1 = new Jugador();
    e1 = new Enemigo();

    //Inicializo una Alcantarilla
    Alcantarilla *alc1 = new Alcantarilla(sf::Vector2f(350,270));
     Alcantarilla *alc2 = new Alcantarilla( sf::Vector2f(500,500));
    alcantarillas.push_back(alc1);
     alcantarillas.push_back(alc2);


}

int Mundo::getPtoEntregaActual()
{
    return ptoEntrgaActual;
}

std::vector<Item*> Mundo::getItems()
{
    return items;
}

std::vector<sf::Vector2f> Mundo::getPuntosEntrega()
{
    return puntosEntrega;
}

void Mundo::colisionAlcantarilla(){

/// Colisiones con las alcantarillas
    for( int i = 0; i < alcantarillas.size(); i++ ) {
        if(p1->getSprite().getGlobalBounds().intersects(alcantarillas[i]->getForma().getGlobalBounds())){

            /**Comprobamos destino**/
            if(i==alcantarillas.size()-1){
            p1->getPhysicsState()->MoveTo((double)alcantarillas[0]->getPosInicial().x+30, (double)alcantarillas[0]->getPosInicial().y);
            }else{
            p1->getPhysicsState()->MoveTo((double)alcantarillas[i+1]->getPosInicial().x+30, (double)alcantarillas[i+1]->getPosInicial().y);
            }


            std::cout<<"Destino Alcanzado x: "<<p1->getPhysicsState()->getActualState()[0]<<std::endl;
            // p1->updateJugador();

        }
    }

}

void Mundo::procesarColisiones()
{
    /// Colisiones con los puntos de entrega
    /*if(jugador->getGlobalBounds().intersects(ptoEntrega->getGlobalBounds())){
        //jugador.puntuacion + 10;
        if(ptoEntrgaActual == puntosEntrega.size() - 1){
            ptoEntrgaActual = 0;
        }else {
            ptoEntrgaActual++;
        }
        ptoEntrega.setPosition(puntosEntrega[ptoEntrgaActual]);
    }*/
    /// TODO: Falta el jugador para ver las colisiones
    /*for(int i = 0; i < items.size(); i++) {
        if(items[i]->getSprite().getGlobalBounds().intersects(jugador)){
            // Colision del jugador con uno de los powerUps del vector
            switch (items[i]->getTipo) {
                case 1:
                    //Colisiona con una vida
                    // player->vida += 1
                    items[i]->restartPowerUp();
                break;
                case 2:
                    // Colisiona con un tiempo
                    // juego->tiempo += 10
                    items[i]->restartPowerUp();
                break;
            }
        }
    }*/

    colisionAlcantarilla();


}

void Mundo::updateMundo(bool eRight, bool eLeft, bool eUp, bool eDown, sf::Time t)
{

    if(mapa->checkearColision(p1->getSprite().getGlobalBounds()))
    {
        //cout << "COLISIONA" << endl;

        eLeft = false;
    }
    else
    {
        //cout << "NO COLISINA CARLOS" << endl;
    }
    procesarColisiones();
    p1->updateJugador(eRight,eLeft,eUp,eDown,t);
    e1->updateEnemigo(p1->getPhysicsState()->getActualState()[0],p1->getPhysicsState()->getActualState()[1],t);



}


void Mundo::drawItems(sf::RenderWindow * ventana){

        // Dibujo los powerUps
    for( int i = 0; i < items.size(); i++ )
    {
        float duracion = items[i]->getClock().getElapsedTime().asSeconds();
        if(duracion > items[i]->getTiempoGeneracion() && duracion < items[i]->getTiempoVida() + items[i]->getTiempoGeneracion())
        {
            ventana->draw(items[i]->getSprite());
        }
        if(duracion > items[i]->getTiempoVida() + items[i]->getTiempoGeneracion())
        {
            items[i]->restartPowerUp();
        }

    }


}

void Mundo::drawAlcantarillas(sf::RenderWindow * ventana){


    for(int i = 0; i < alcantarillas.size(); i++ ){
        alcantarillas[i]->drawAlcantarilla(ventana);
    }


}

void Mundo::drawMundo(sf::RenderWindow * ventana, double inter)
{
    // Dubujo el punto de entrega
    mapa->draw(ventana);
    this->drawAlcantarillas(ventana);
    this->drawItems(ventana);
    ventana->draw(*ptoEntrega);


    p1->drawJugador(ventana,inter);
    e1->drawEnemigo(ventana,inter);


}

Mundo::~Mundo()
{
    //dtor
}
