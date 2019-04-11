#ifndef TRAFICO_H
#define TRAFICO_H
#include <SFML/Graphics.hpp>


class Trafico
{
    public:
        Trafico(int tipo, sf::Vector2f pos);
        virtual ~Trafico();
        int getTipo();
        sf::Clock getClock();
        sf::Sprite getSprite();
        sf::Vector2f getPosicion();
    protected:
    private:
        int tipo;
        sf::Clock reloj;
        sf::Vector2f posicion;
        sf::Sprite *coche;
        sf::Texture textura;

};

#endif // TRAFICO_H

