#include "Mundo.h"

Mundo::Mundo() {
    //ctor
    ptoEntrgaActual = 0;

    // Creo los PoweUPs
    Item *vida1 = new Item(1, sf::Vector2f(360,150), 2, 60);
    items.push_back(vida1);
    Item *tiempo1 = new Item(2, sf::Vector2f(420,425), 2,60);
    items.push_back(tiempo1);
}

int Mundo::getPtoEntregaActual() {
    return ptoEntrgaActual;
}

std::vector<Item*> Mundo::getItems() {
    return items;
}

std::vector<sf::Vector2f> Mundo::getPuntosEntrega() {
    return puntosEntrega;
}

void Mundo::procesarColisiones() {
    /// TODO: Falta el jugador para ver las colisiones
    /*for(int i = 0; i < items.size(); i++) {
        if(items[i]->getSprite().getGlobalBounds().intersects(jugador)){
            // Colision del jugador con uno de los powerUps del vector
            switch (items[i]->getTipo) {
                case 1:
                    //Colisiona con una vida
                    // player->vida += items[i]->getVida()
                break;
                case 2:
                    // Colisiona con un tiempo
                    // juego->tiempo += items[i]->getTiempo()
                break;
            }
        }
    }*/
}

void Mundo::draw(sf::RenderWindow * window) {
    // Dibujo los powerUps
    for( int i = 0; i < items.size(); i++ ){
        window->draw(items[i]->getSprite());
    }

}

Mundo::~Mundo()
{
    //dtor
}
