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

    /** HUD, vista and minimap stuff **/
    // HUD
    player_lifes = 5;
    num_pizzas = 0;
    txt_pizza = new Texture();
    txt_pizza -> loadFromFile("assets/hud/pizza.png");
    spr_pizza = new Sprite(*txt_pizza);
    spr_pizza ->setPosition(100,100);
//    spr_pizza -> setScale(50.f/190, 50.f/200);
    // Vista
    vista = new View();
    vista -> reset(sf::FloatRect(p1->getPhysicsState().getActualState()[0],p1->getPhysicsState().getActualState()[1], 300, 200));
    vista->setCenter((float)p1->getPhysicsState().getActualState()[0], (float)p1->getPhysicsState().getActualState()[1]);
    vista->setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    // Minimap
    minimap = new View();
    minimap->setViewport(sf::FloatRect(0.75f, 0.75f, 0.25f, 0.25f));

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
}

void Mundo::updateMundo(bool eRight, bool eLeft, bool eUp, bool eDown, sf::Time t)
{

    if(mapa->checkearColision(p1->getSprite().getGlobalBounds()))
    {
        cout << "COLISIONA" << endl;

//        eLeft = false;
    }
    else
    {
        cout << "NO COLISINA CARLOS" << endl;
    }

    p1->updateJugador(eRight,eLeft,eUp,eDown,t);
    e1->updateEnemigo(p1->getPhysicsState().getActualState()[0],p1->getPhysicsState().getActualState()[1],t);
    procesarColisiones();

    /** Updateamos la updatecamara para que updatesiga al updatejugador **/
//    vista->setCenter(p1->getPhysicsState().getActualState()[0],p1->getPhysicsState().getActualState()[1]);
//    vista->setCenter(p1->renderPos[0],p1->renderPos[1]);
    vista->move(p1->getPhysicsState().getActualState()[0] - p1->getPhysicsState().getPastState()[0], p1->getPhysicsState().getActualState()[1] - p1->getPhysicsState().getPastState()[1]);
        processHUD();


}

/**Metodo para processar los elementos del HUD*/
void Mundo::processHUD()
{

// Esta por hacer

}

void Mundo::drawMundo(sf::RenderWindow * ventana, double inter)
{
    // Dubujo el punto de entrega
    mapa->draw(ventana);
    ventana->draw(*ptoEntrega);
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
    p1->drawJugador(ventana,inter);
    e1->drawEnemigo(ventana,inter);
    ventana->setView(*minimap);
    // Hasta aqui el minimap.

    mapa->draw(ventana);
    ventana->draw(*ptoEntrega);
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
    p1->drawJugador(ventana,inter);
    e1->drawEnemigo(ventana,inter);
    ventana->setView(*vista);
    // Hasta aqui la vista principal.



}

Mundo::~Mundo()
{
    //dtor
}
