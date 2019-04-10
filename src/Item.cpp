#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(int tipo, sf::Vector2f pos, int tiempoG, int tiempoV) {
    //ctor
    tipo = tipo;
    posicion = pos;
    tiempoGeneracion = tiempoG;
    tiempoVida = tiempoV;
    /// TODO: cargar el spriteSheet
    textura.loadFromFile("assets/PowerUps/PowerUps.png");
    if (!textura.loadFromFile("assets/PowerUps/PowerUps.png"))
    {
        std::cout<< "Error cargando la imagen PowerUps.png"<<std::endl;
        exit(0);
    }
    sprite = new sf::Sprite();
    sprite->setTexture(textura);
    /// TODO: En funcion del tipo de item escoger la zona de recorte para poner la
    /// imagen a cada tipo de powerUp
    switch (tipo) {
        case 1:
            /// Vida Extra
            sprite->setTextureRect(sf::IntRect(3,15,92,74));
            sprite->setOrigin(92/2,74/2);
            sprite->setScale(0.4,0.4);
        break;
        case 2:
            /// Turbo
            sprite->setTextureRect(sf::IntRect(23,95,61,93));
            sprite->setOrigin(61/2,93/2);
            sprite->setScale(0.4,0.4);
        break;
        case 3:
            /// Tiempo Extra
        break;
        case 4:
            /// Invisibilidad
        break;
    }
    sprite->setPosition(pos.x, pos.y);
}

int Item::getTipo() {
    return tipo;
}

int Item::getTiempoVida() {
    return tiempoVida;
}

int Item::getTiempoGeneracion() {
    return tiempoGeneracion;
}

sf::Clock Item::getClock() {
    return reloj;
}

sf::Sprite Item::getSprite(){
    return *sprite;
}

sf::Vector2f Item::getPosicion() {
    return posicion;
}

Item::~Item()
{
    //dtor
}
