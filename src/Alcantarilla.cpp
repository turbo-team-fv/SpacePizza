#include "Alcantarilla.h"
#include <SFML/Graphics.hpp>"

Alcantarilla::Alcantarilla(sf::Vector2f posI)
{
    //ctor
    posInicial = posI;

    forma = new sf::CircleShape(8);
    forma->setFillColor(sf::Color::Green);
    forma->setPosition(posInicial.x, posInicial.y);
}

sf::Vector2f Alcantarilla::getPosInicial(){
    return posInicial;
}


sf::CircleShape Alcantarilla::getForma(){
    return *forma;
}

void Alcantarilla::drawAlcantarilla(sf::RenderWindow *ventana){
    ventana->draw(*forma);
}

Alcantarilla::~Alcantarilla()
{
    //dtor
}
