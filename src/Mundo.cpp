#include "Mundo.h"

Mundo::Mundo() {
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

    //COL 1
    Trafico *coche1 = new Trafico(1, sf::Vector2f(55,290));
    Trafico *coche2 = new Trafico(1, sf::Vector2f(55,435));
    Trafico *coche3= new Trafico(1, sf::Vector2f(70,675));
    Trafico *coche4 = new Trafico(1, sf::Vector2f(70,785));
    Trafico *coche5 = new Trafico(1, sf::Vector2f(70,895));
    //COL 2
    Trafico *coche6 = new Trafico(1, sf::Vector2f(375,50));
    Trafico *coche7 = new Trafico(1, sf::Vector2f(375,290));
    Trafico *coche8 = new Trafico(1, sf::Vector2f(375,435));
    Trafico *coche9 = new Trafico(1, sf::Vector2f(375,675));
    Trafico *coche10 = new Trafico(1, sf::Vector2f(375,895));

    Trafico *coche11 = new Trafico(1, sf::Vector2f(660,50));
    Trafico *coche12 = new Trafico(1, sf::Vector2f(660,290));
    Trafico *coche13 = new Trafico(1, sf::Vector2f(660,435));
    Trafico *coche14 = new Trafico(1, sf::Vector2f(660,675));
    Trafico *coche15 = new Trafico(1, sf::Vector2f(660,895));


    Trafico *coche16 = new Trafico(1, sf::Vector2f(900,50));
    Trafico *coche17 = new Trafico(1, sf::Vector2f(900,290));
    Trafico *coche18 = new Trafico(1, sf::Vector2f(900,675));
    Trafico *coche19 = new Trafico(1, sf::Vector2f(900,895));

    trafico.push_back(coche1);
    trafico.push_back(coche2);
    trafico.push_back(coche3);
    trafico.push_back(coche4);
    trafico.push_back(coche5);
    trafico.push_back(coche6);
    trafico.push_back(coche7);
    trafico.push_back(coche8);
    trafico.push_back(coche9);
    trafico.push_back(coche10);
    trafico.push_back(coche11);
    trafico.push_back(coche12);
    trafico.push_back(coche13);
    trafico.push_back(coche14);
    trafico.push_back(coche15);
    trafico.push_back(coche16);
    trafico.push_back(coche17);
    trafico.push_back(coche18);
    trafico.push_back(coche19);

    movimientoTrafico();
}

int Mundo::getPtoEntregaActual() {
    return ptoEntrgaActual;
}

std::vector<Item*> Mundo::getItems() {
    return items;
}

std::vector<Trafico*> Mundo::getTrafico() {
    return trafico;

}

std::vector<sf::Vector2f> Mundo::getPuntosEntrega() {
    return puntosEntrega;
}

sf::Clock Mundo::getClock() {
    return clock;
}
sf::Time Mundo::getTime() {
    return time;
}
void Mundo::movimientoTrafico(){

time = clock.getElapsedTime();

        if(time.asSeconds()>=0.005){
            if(trafico[0]->getX()<=346 && trafico[0]->getY()<=290){
                trafico[0]->movera(sf::Vector2f(2,0));
            }
            if(trafico[0]->getX()>=346 && trafico[0]->getY()<=410){
                trafico[0]->movera(sf::Vector2f(0,2));
            }

            if(trafico[0]->getX()<=350 && trafico[0]->getY()>=410){
                trafico[0]->movera(sf::Vector2f(-2,0));
            }

            if(trafico[0]->getX()<=55 && trafico[0]->getY()<=410){
                trafico[0]->movera(sf::Vector2f(0,-2));
            }
            clock.restart();
        }

}

void Mundo::procesarColisiones() {
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

void Mundo::draw(sf::RenderWindow * window) {
    // Dubujo el punto de entrega
    window->draw(*ptoEntrega);


    // Dibujo los powerUps
    for( int i = 0; i < items.size(); i++ ){
        float duracion = items[i]->getClock().getElapsedTime().asSeconds();
        if(duracion > items[i]->getTiempoGeneracion() && duracion < items[i]->getTiempoVida() + items[i]->getTiempoGeneracion()){
            window->draw(items[i]->getSprite());
        }
        if(duracion > items[i]->getTiempoVida() + items[i]->getTiempoGeneracion()){
            items[i]->restartPowerUp();
        }

    }

    /*sf::Clock clock;
    sf::Time time;
    time = clock.getElapsedTime();
    for(int j = 0; j < trafico.size(); j++ ){
        if(time.asSeconds()>1 && trafico[j]->getPosicion().x > 0){
        trafico[j]->move(sf::Vector2f(1000,0));
        }
    }*/
    window->draw(trafico[0]->getSprite());
    window->draw(trafico[1]->getSprite());
    window->draw(trafico[2]->getSprite());
    window->draw(trafico[3]->getSprite());
    window->draw(trafico[4]->getSprite());
    window->draw(trafico[5]->getSprite());
    window->draw(trafico[6]->getSprite());
    window->draw(trafico[7]->getSprite());
    window->draw(trafico[8]->getSprite());
    window->draw(trafico[9]->getSprite());
    window->draw(trafico[10]->getSprite());
    window->draw(trafico[11]->getSprite());
    window->draw(trafico[12]->getSprite());
    window->draw(trafico[13]->getSprite());
    window->draw(trafico[14]->getSprite());
    window->draw(trafico[15]->getSprite());
    window->draw(trafico[16]->getSprite());
    window->draw(trafico[17]->getSprite());
    window->draw(trafico[18]->getSprite());


}

Mundo::~Mundo()
{
    //dtor
}
