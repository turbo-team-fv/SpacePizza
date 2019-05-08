#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(int tipo, sf::Vector2f pos, int tiempoG, int tiempoV) {
    //ctor
    // this->tipo = tipo;
    posicion = pos;
    tiempoGeneracion = tiempoG;
    tiempoVida = tiempoV;
    /// Carga el spriteSheet
    textura.loadFromFile("assets/PowerUps/power.png");
    if (!textura.loadFromFile("assets/PowerUps/power.png"))
    {
        std::cout<< "Error cargando la imagen PowerUps.png"<<std::endl;
        exit(0);
    }
    sprite = new sf::Sprite();
    sprite->setTexture(textura);
    activo = false;
    /// En funcion del tipo de item escoger la zona de recorte para poner la
    /// imagen a cada tipo de powerUp
    setTipo(tipo);
    sprite->setPosition(pos.x, pos.y);
}

void Item::drawItem(sf::RenderWindow * ventana) {
    activo = true;
    ventana->draw(*sprite);
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

void Item::restartPowerUp() {
    activo = false;
    reloj.restart();
    /// Cambiar el tipo del powerUp
    int tipo = 1 + rand() % 5;
    setTipo(tipo);

}

void Item::setTipo(int tipo){
    this->tipo = tipo;
    switch (tipo) {
        case 1:
            /// Vida Extra
            sprite->setTextureRect(sf::IntRect(134,13,92,96));
            sprite->setOrigin(92/2,96/2);
            sprite->setScale(0.2,0.2);
        break;
        case 2:
            /// Turbo
            sprite->setTextureRect(sf::IntRect(25,135,67,90));
            sprite->setOrigin(67/2,90/2);
            sprite->setScale(0.2,0.2);
        break;
        case 3:
            /// Tiempo Extra
            sprite->setTextureRect(sf::IntRect(150,133,63,94));
            sprite->setOrigin(63/2,94/2);
            sprite->setScale(0.2,0.2);
        break;
        case 4:
            /// Invisibilidad
            sprite->setTextureRect(sf::IntRect(258,15,91,92));
            sprite->setOrigin(92/2, 92/2);
            sprite->setScale(0.2,0.2);
        break;
        case 5:
            /// Levitar
        break;
        case 6:
            /// Modo Imparable
        break;
    }
}

bool Item::isActivo(){
    return activo;
}

Item::~Item()
{
    //dtor
}
