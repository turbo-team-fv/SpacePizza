#include "Trafico.h"
#include <iostream>

Trafico::Trafico(int tipo, sf::Vector2f pos){
    //ctor
    tipo = tipo;
    posicion = pos;
    textura=new sf::Texture();
    textura->loadFromFile("assets/Trafico/roguelikeCity_magenta2.png");
    if (!textura->loadFromFile("assets/Trafico/roguelikeCity_magenta2.png"))
    {
        std::cout<< "Error cargando la imagen roguelikeCity_magenta2.png"<<std::endl;
        exit(0);
    }
    coche = new sf::Sprite();
    coche->setTexture(*textura);
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




    /*

        sf::Clock clock;
        sf::Time time;

    t   time = clock.getElapsedTime();
        time2 = clock2.getElapsedTime();
        time3 = clock3.getElapsedTime();
        time4 = clock4.getElapsedTime();
        time5 = clock5.getElapsedTime();

        if(time.asSeconds()>=0.15 && enemigo.getPosition().x>260 && enemigo.getPosition().y==166){
            enemigo.move(sf::Vector2f(-5,0));
            clock.restart();
        }

    */

}
void Trafico::der(){
    coche->setTextureRect(sf::IntRect(583,416,38,25));
}
void Trafico::abajo(){
    coche->setTextureRect(sf::IntRect(566,444,23,30));
}
void Trafico::izq(){
    coche->setTextureRect(sf::IntRect(534,416,38,25));
}
void Trafico::arriba(){
    coche->setTextureRect(sf::IntRect(532,444,23,30));
}

void Trafico::movera(sf::Vector2f dir){
     coche->move(dir);
 }

int Trafico::getTipo() {
    return tipo;
}



sf::Sprite Trafico::getSprite(){
    return *coche;
}

int Trafico::getX(){
     return coche->getPosition().x;
 }

 int Trafico::getY(){
    return coche->getPosition().y;
 }
 void Trafico::rotate(float angle){
     coche->rotate(angle);
 }

void Trafico::draw(sf::RenderWindow &window){
        window.draw(*coche);
    }

Trafico::~Trafico()
{
    //dtor
}


