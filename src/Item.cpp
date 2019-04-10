#include "Item.h"

Item::Item(int tipo, sf::Vector2f pos, int tiempoG, int tiempoV) {
    //ctor
    tipo = tipo;
    posicion = pos;
    tiempoGeneracion = tiempoG;
    tiempoVida = tiempoV;
    /// TODO: cargar el spriteSheet
    /*textura.loadFromFile("resources/egg.png");
    if (!textura.loadFromFile("resources/egg.png"))
    {
        std::cout<< "Error cargando la imagen sp_alien_texture.png"<<std::endl;
        exit(0);
    }*/
    sprite = new sf::Sprite();
    sprite->setTexture(textura);
    // sprite->setOtigin() valores del tamaño del sprite divididos por 2
    /// TODO: En funcion del tipo de item escoger la zona de recorte para poner la
    /// imagen a cada tipo de powerUp
    switch (tipo) {
        case 1:
            /// Vida Extra
            // sprite->setTextureRect(sf::IntRect(0,0,64,77))
        break;
        case 2:
            /// Turbo
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
