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
    textura.loadFromFile("assets/PowerUps/powerUps.png");
    if (!textura.loadFromFile("assets/PowerUps/powerUps.png"))
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
    setTipo(this->tipo);

}

void Item::setTipo(int tipo){
    this->tipo = tipo;
    switch (tipo) {
        case 1:
            /// Vida Extra
            sprite->setTextureRect(sf::IntRect(29,18,49,76));
            sprite->setOrigin(49/2,76/2);
            sprite->setScale(0.3,0.3);
        break;
        case 2:
            /// Turbo
            sprite->setTextureRect(sf::IntRect(150,14,48,80));
            sprite->setOrigin(48/2,80/2);
            sprite->setScale(0.3,0.3);
        break;
        case 3:
            /// Tiempo Extra
            sprite->setTextureRect(sf::IntRect(30,134,49,80));
            sprite->setOrigin(49/2,80/2);
            sprite->setScale(0.3,0.3);
        break;
        case 4:
            /// Invisibilidad
            sprite->setTextureRect(sf::IntRect(270,13,49,81));
            sprite->setOrigin(49/2, 81/2);
            sprite->setScale(0.3,0.3);
        break;
        case 5:
            /// Levitar
            sprite->setTextureRect(sf::IntRect(149,135,51,79));
            sprite->setOrigin(51/2, 79/2);
            sprite->setScale(0.3,0.3);
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
