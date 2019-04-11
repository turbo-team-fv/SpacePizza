#include "Trafico.h"
#include <iostream>

Trafico::Trafico(int tipo, sf::Vector2f pos){
    //ctor
    tipo = tipo;
    posicion = pos;

    textura.loadFromFile("assets/Trafico/roguelikeCity_magenta2.png");
    if (!textura.loadFromFile("assets/Trafico/roguelikeCity_magenta2.png"))
    {
        std::cout<< "Error cargando la imagen roguelikeCity_magenta2.png"<<std::endl;
        exit(0);
    }
    coche = new sf::Sprite();
    coche->setTexture(textura);
    //segun el tipo de coche que sea. el color puede determinar la velocidad del coche??
    switch (tipo) {
        case 1:
            /// Coche rojo
            coche->setTextureRect(sf::IntRect(583,416,38,25));
            coche->setOrigin(38/2,25/2);
            coche->setScale(1,1);
        break;
        case 2:
            /// Coche Azul
            coche->setTextureRect(sf::IntRect(583,348,38,25));
            coche->setOrigin(38/2,25/2);
            coche->setScale(1,1);
        break;
        case 3:
            /// Coche Verde
            coche->setTextureRect(sf::IntRect(583,280,38,25));
            coche->setOrigin(38/2,25/2);
            coche->setScale(1,1);
        break;
    }
    coche->setPosition(pos.x, pos.y);

}

int Trafico::getTipo() {
    return tipo;
}

sf::Clock Trafico::getClock() {
    return reloj;
}

sf::Sprite Trafico::getSprite(){
    return *coche;
}

sf::Vector2f Trafico::getPosicion() {
    return posicion;
}

Trafico::~Trafico()
{
    //dtor
}



