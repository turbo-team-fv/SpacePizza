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
        void updateJugador(double velx, double vely, sf::Time et);
        void drawJugador(sf::RenderWindow *w, double i);


    protected:

     private:
    /**GRAFICOS**/
    sf::Texture  tex;
    sf::Sprite  spri;
    vector<double> renderPos;

    /**FISICAS**/
    PhysicsState pState;
};

#endif // JUGADOR_H
