#ifndef TRAFICO_H
#define TRAFICO_H
#include <SFML/Graphics.hpp>
#include "PhysicsState.h"


class Trafico
{
    public:
        Trafico(int tipo, sf::Vector2f pos);
        virtual ~Trafico();
        int getTipo();
        sf::Sprite getSprite();
        sf::Vector2f getPosicion();
        int getX();
        int getY();
        void movera(sf::Vector2f dir);
        void draw(sf::RenderWindow &window);
        void rotate(float angle);

        void der();
        void abajo();
        void izq();
        void arriba();

    protected:
    private:
        int tipo;
        sf::Vector2f posicion;
        sf::Sprite *coche;
        sf::Texture *textura;

};

#endif // TRAFICO_H

