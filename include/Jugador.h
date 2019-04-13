#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "PhysicsState.h"
using namespace std;


class Jugador
{
    public:
        Jugador();
        virtual ~Jugador();
        PhysicsState getPhysicsState();
        void updateJugador(bool eRight,bool eLeft,bool eUp,bool eDown, sf::Time et);
        void drawJugador(sf::RenderWindow *w, double i);
        vector<double> renderPos;
        sf::Sprite getSprite(){ return spri; };

    protected:

     private:
    /**GRAFICOS**/
    sf::Texture  tex;
    sf::Sprite  spri;


    /**FISICAS**/
    PhysicsState pState;
};

#endif // JUGADOR_H
