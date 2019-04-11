#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "PhysicsState.h"

class Enemigo
{
    public:
        Enemigo();
        virtual ~Enemigo();
        PhysicsState getPhysicsState();
        void updateEnemigo(double velx, double vely, sf::Time et);
        void drawEnemigo(sf::RenderWindow *w, double i);

    protected:

    private:
    /**GRAFICOS**/
    sf::Texture  tex;
    sf::Sprite  spri;
    vector<double> renderPos;

    /**FISICAS**/
    PhysicsState pState;

    /**OTROS**/
    int actitud; //0: Apatrullando la ciudad, 1: En alerta, 2: Te persigue
    double tiempo_espera; // sera un random de espera entre movimiento y movimiento
    sf::Clock movingclock;
    sf::Clock alertclock;

    sf::Clock actitudTest;

    int direccion_patrullaje; // 0: quieto, 1: izquierda, 2: derecha, 3: arriba, 4: abajo
    int direccion_patrullaje2; // 0: quieto, 1: izquierda, 2: derecha, 3: arriba, 4: abajo

};

#endif // ENEMIGO_H
