#include "Mundo.h"
#include "Juego.h"

Mundo::Mundo()
{
    //ctor
    ptoEntrgaActual = 0;
    pizzas = 0;

    // Inicializo los puntos de entrega
    initPuntosEntrega();
    //inicializo los items
    initItems();


    /**EELEMENTOS**/
    mapa = new Mapa();
    p1 = new Jugador();
    e1 = new Enemigo();

    tiempo = 10;

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

void Mundo::procesarColisiones()
{
    /// Colisiones con los puntos de entrega
    if(puntoEntrega->getGlobalBounds().intersects(p1->getSprite().getGlobalBounds())){
        //jugador.puntuacion + 10;
        if(ptoEntrgaActual == puntosEntrega.size() - 1){
            ptoEntrgaActual = 0;
        }else {
            ptoEntrgaActual++;
        }
        puntoEntrega->setPosition(puntosEntrega[ptoEntrgaActual]);
        pizzas++;
    }
    /// Colisones con los PowerUps
    for(int i = 0; i < items.size(); i++) {
        if(items[i]->getSprite().getGlobalBounds().intersects(p1->getSprite().getGlobalBounds()) && items[i]->isActivo()){
            // Colision del jugador con uno de los powerUps del vector
            std::cout<<"Colision con un item"<<std::endl;
            int tipo = items[i]->getTipo();
            std::cout<<tipo<<std::endl;
            switch (tipo) {
                case 1:
                    //Colisiona con una vida
                    items[i]->restartPowerUp();
                    p1->updateVida(1);
                break;
                case 2:
                    // Colisiona con un turbo => aumenta la velocidad durante un perido de tiempo
                    items[i]->restartPowerUp();
                break;
                case 3:
                    // Colisiona con un tiempo
                    // juego->tiempo += 10
                    //Juego.getInstance()->updateTime(10);
                    tiempo += 10;
                    items[i]->restartPowerUp();
                break;
                case 4:
                    // Colisiona con una invisibilidad => cambiar la IA del Enemigo?
                    items[i]->restartPowerUp();
                break;
            }
        }
    }
}

void Mundo::updateMundo(bool eRight, bool eLeft, bool eUp, bool eDown, sf::Time t)
{

    if(mapa->checkearColision(p1->getSprite().getGlobalBounds()))
    {
        //cout << "COLISIONA" << endl;

        //eLeft = false;
    }
    else
    {
        //cout << "NO COLISINA CARLOS" << endl;
    }

    p1->updateJugador(eRight,eLeft,eUp,eDown,t);
    e1->updateEnemigo(p1->getPhysicsState().getActualState()[0],p1->getPhysicsState().getActualState()[1],t);
    procesarColisiones();


}
void Mundo::drawMundo(sf::RenderWindow * ventana, double inter)
{
    // Dubujo el punto de entrega
    mapa->draw(ventana);
    ventana->draw(*puntoEntrega);
    // Dibujo los powerUps
    for( int i = 0; i < items.size(); i++ )
    {
        float duracion = items[i]->getClock().getElapsedTime().asSeconds();
        if(duracion > items[i]->getTiempoGeneracion() && duracion < items[i]->getTiempoVida() + items[i]->getTiempoGeneracion())
        {
            items[i]->drawItem(ventana);
        }
        if(duracion > items[i]->getTiempoVida() + items[i]->getTiempoGeneracion())
        {
            items[i]->restartPowerUp();
        }

    }
    p1->drawJugador(ventana,inter);
    e1->drawEnemigo(ventana,inter);


}

int Mundo::getTime(){
    return tiempo;
}

void Mundo::initPuntosEntrega(){
    /// Inicializo la textura del punto de entrega
    texture.loadFromFile("assets/PowerUps/power.png");
    if (!texture.loadFromFile("assets/PowerUps/power.png"))
    {
        std::cout<< "Error cargando la imagen PowerUps.png"<<std::endl;
        exit(0);
    }
    /// Pongo el sprite del punto de entrega
    puntoEntrega = new sf::Sprite();
    puntoEntrega->setTexture(texture);
    puntoEntrega->setTextureRect(sf::IntRect(15,16,88,89));
    puntoEntrega->setOrigin(88/2,89/2);
    puntoEntrega->setScale(0.5,0.5);

    /// Situo los puntos de entrega disponibles
    puntosEntrega.push_back(sf::Vector2f(150,150));
    puntosEntrega.push_back(sf::Vector2f(500,500));

    puntoEntrega->setPosition(puntosEntrega[0]);
}

void Mundo::initItems(){
    /// Creo un item de cada tipo en una posicion determinada con un tiempo de
    /// vida y de generacion
    Item *vida1 = new Item(1, sf::Vector2f(360,150), 2, 5);
    items.push_back(vida1);
    Item *turbo = new Item(2, sf::Vector2f(420,425), 2,10);
    items.push_back(turbo);
    Item *tiempo = new Item(3, sf::Vector2f(100,425), 2,10);
    items.push_back(tiempo);
    Item *inivisibilidad = new Item(4, sf::Vector2f(100,280), 2,10);
    items.push_back(inivisibilidad);
}

Mundo::~Mundo()
{
    //dtor
}
