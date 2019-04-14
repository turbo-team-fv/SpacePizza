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
    vista -> reset(sf::FloatRect(p1->getPhysicsState()->getActualState()[0],p1->getPhysicsState()->getActualState()[1], 300, 200));
    vista->setCenter((float)p1->getPhysicsState()->getActualState()[0], (float)p1->getPhysicsState()->getActualState()[1]);
    vista->setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    // Minimap
    minimap = new View();
    minimap->setViewport(sf::FloatRect(0.75f, 0.75f, 0.25f, 0.25f));

    tiempo = 10;

    initAlcantarillas();
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

void Mundo::colisionesMapa()
{

    float offset=0;
    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[0])!=0)
    {

        p1->getPhysicsState()->Move(0,-100,true);

    }

    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[1])!=0)
    {

        p1->getPhysicsState()->Move(+100,0,true);
//        eLeft = false;
    }

    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[2])!=0)
    {

        p1->getPhysicsState()->Move(-100,0,true);
        // eRight = false;
    }

    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[3])!=0)
    {

        p1->getPhysicsState()->Move(0,+100,true);
        //  eUp = false;
    }


}

void Mundo::colisionAlcantarilla(bool eRight, bool eLeft, bool eUp, bool eDown, sf::Time t){

/// Colisiones con las alcantarillas
    for( int i = 0; i < alcantarillas.size(); i++ ) {
        if(p1->getSprite()->getActualSprite()->getGlobalBounds().intersects(alcantarillas[i]->getSprite().getGlobalBounds())){
            p1->getPhysicsState()->MoveTo((double) 500, (double) 425);
            // p1->getPhysicsState()->MovePlayerTo((double) 500, (double) 425);

            /**Comprobamos destino**/
           /* if(i == alcantarillas.size() -1){


                if(eRight) {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[0]->getPosInicial().x+30, (double)alcantarillas[0]->getPosInicial().y);
                }else if(eLeft) {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[0]->getPosInicial().x-30, (double)alcantarillas[0]->getPosInicial().y);
                }else if(eDown) {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[0]->getPosInicial().x, (double)alcantarillas[0]->getPosInicial().y+30);
                }else if(eUp) {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[0]->getPosInicial().x, (double)alcantarillas[0]->getPosInicial().y-30);
                }

            }else{
                if(eRight) {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[i+1]->getPosInicial().x+30, (double)alcantarillas[i+1]->getPosInicial().y);
                }else if(eLeft) {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[i+1]->getPosInicial().x-30, (double)alcantarillas[i+1]->getPosInicial().y);
                }else if(eDown) {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[i+1]->getPosInicial().x, (double)alcantarillas[i+1]->getPosInicial().y+30);
                }else if(eUp) {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[i+1]->getPosInicial().x, (double)alcantarillas[i+1]->getPosInicial().y-30);
                }
            }*/
            std::cout<<"Destino Alcanzado x: "<<p1->getPhysicsState()->getActualState()[0]<<std::endl;
        }
    }

}

void Mundo::procesarColisiones(bool eRight, bool eLeft, bool eUp, bool eDown,sf::Time t)
{

    colisionesMapa();
    /// Colisiones con los puntos de entrega
    if(puntoEntrega->getGlobalBounds().intersects(p1->getSprite()->getActualSprite()->getGlobalBounds())){
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
        if(items[i]->getSprite().getGlobalBounds().intersects(p1->getSprite()->getActualSprite()->getGlobalBounds()) && items[i]->isActivo()){
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

    colisionAlcantarilla(eRight,eLeft, eUp, eDown, t);


}

void Mundo::updateMundo(bool eRight, bool eLeft, bool eUp, bool eDown, sf::Time t)
{
    procesarColisiones(eRight,eLeft,eUp,eDown, t);
    p1->updateJugador(eRight,eLeft,eUp,eDown,t);
    e1->updateEnemigo(p1->getPhysicsState()->getActualState()[0],p1->getPhysicsState()->getActualState()[1],t);


    /** Updateamos la updatecamara para que updatesiga al updatejugador **/
//vista->setCenter(p1->getPhysicsState().getActualState()[0],p1->getPhysicsState().getActualState()[1]);
//   vista->setCenter(p1->renderPos[0],p1->renderPos[1]);
    //vista->move(p1->getPhysicsState()->getVel()[0],p1->getPhysicsState()->getVel()[1]);
    //vista->move(p1->getPhysicsState().getActualState()[0] - p1->getPhysicsState().getPastState()[0], p1->getPhysicsState().getActualState()[1] - p1->getPhysicsState().getPastState()[1]);
    processHUD();


}

/**Metodo para processar los elementos del HUD*/
void Mundo::processHUD()
{

// Esta por hacer

}

void Mundo::drawItems(sf::RenderWindow * ventana)
{


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
}



void Mundo::drawMundo(sf::RenderWindow * ventana, double inter)
{
    /***PRIMERO RECALCULAMOS POSICION DE OBJETOS INTERPOLADOS***/
    /**Por algun motivo que no acabo de comprender**/
    p1->calcInter(ventana,inter);
    //e1->calcInter(ventana,inter);


    vista->setCenter(p1->getSprite()->getRenderPos()[0],p1->getSprite()->getRenderPos()[1]);///SET CAMERA PLAYER
    ventana->setView(*vista);///SET VIEW PLAYER
    mapa->draw(ventana);
    ventana->draw(*puntoEntrega);
    drawItems(ventana);
    drawAlcantarillas(ventana);

    p1->drawJugador(ventana,inter);
    e1->drawEnemigo(ventana,inter);
    p1->getPhysicsState()->drawColliders(ventana, inter);

    ventana->setView(*minimap);///SET VIEW MAP
    mapa->draw(ventana);
    ventana->draw(*puntoEntrega);
    drawItems(ventana);
    p1->drawJugador(ventana,inter);
    e1->drawEnemigo(ventana,inter);




}

void Mundo::drawAlcantarillas(sf::RenderWindow * ventana){


    for(int i = 0; i < alcantarillas.size(); i++ ){
        alcantarillas[i]->drawAlcantarilla(ventana);
    }

}
/// Metodo para inizializar las Alcantarillas del Mundo
void Mundo::initAlcantarillas() {
    Alcantarilla *alc1 = new Alcantarilla(sf::Vector2f(360,280));
    Alcantarilla *alc2 = new Alcantarilla( sf::Vector2f(360,665));
    alcantarillas.push_back(alc1);
    alcantarillas.push_back(alc2);
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
    puntoEntrega->setScale(0.4,0.4);

    /// Situo los puntos de entrega disponibles
    puntosEntrega.push_back(sf::Vector2f(360,200));
    puntosEntrega.push_back(sf::Vector2f(360,500));

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
