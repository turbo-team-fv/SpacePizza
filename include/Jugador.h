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
        void updateJugador(bool eRight,bool eLeft,bool eUp,bool eDown,sf::Vector2f bounce, sf::Time et);
        void calcInter(sf::RenderWindow *w, double i);
        void drawJugador(sf::RenderWindow *w, double i);
        void updateVida(int change);
        int getVidas();
        int checkEstado();
        void setEstado(int e);
        void setCesped(bool c);
        void restartEstado();
        SuperSprite* getSprite(){ return jugador_sprite; };


    protected:

     private:
    /**GRAFICOS**/
    SuperSprite *jugador_sprite;
    SuperSprite *turbo,*invisible;


    /**FISICAS**/
    PhysicsState *pState;
    int vidas;
    int estado;
    bool cesped;

    sf::Clock timer_estado;
    double limite_estado;

};

#endif // JUGADOR_H
