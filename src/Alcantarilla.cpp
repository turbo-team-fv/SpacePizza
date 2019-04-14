#include "Alcantarilla.h"
#include <SFML/Graphics.hpp>"
#include<iostream>

Alcantarilla::Alcantarilla(sf::Vector2f posI)
{
    //ctor
    posInicial = posI;

    forma = new sf::CircleShape(8);
    forma->setFillColor(sf::Color::Green);
    forma->setPosition(posInicial.x, posInicial.y);
    /// Cargo el SpriteSheet para la alcantarilla
    texture.loadFromFile("assets/PowerUps/power.png");
    if(!texture.loadFromFile("assets/PowerUps/power.png")) {
        std::cout<<"Error cargando la imagen power.png"<<std::endl;
    }
    sprite = new sf::Sprite();
    sprite->setTexture(texture);
    sprite->setTextureRect(sf::IntRect(256,175,91,18));
    sprite->setOrigin(91/2,18/2);
    sprite->setScale(0.3,0.3);
    sprite->setPosition(posI);


}

sf::Vector2f Alcantarilla::getPosInicial(){
    return posInicial;
}


sf::CircleShape Alcantarilla::getForma(){
    return *forma;
}

void Alcantarilla::drawAlcantarilla(sf::RenderWindow *ventana){
    // ventana->draw(*forma);
    ventana->draw(*sprite);
}

Alcantarilla::~Alcantarilla()
{
    //dtor
}
