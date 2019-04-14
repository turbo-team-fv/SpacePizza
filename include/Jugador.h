#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "PhysicsState.h"
#include "SuperSprite.h"
using namespace std;


class Jugador
{
    public:
        Jugador();
        virtual ~Jugador();
        PhysicsState* getPhysicsState();
        void updateJugador(bool eRight,bool eLeft,bool eUp,bool eDown, sf::Time et);
        void drawJugador(sf::RenderWindow *w, double i);
        SuperSprite* getSprite(){ return jugador_sprite; };


    protected:

     private:
    /**GRAFICOS**/
    SuperSprite *jugador_sprite;


    /**FISICAS**/
    PhysicsState *pState;
};

#endif // JUGADOR_H
