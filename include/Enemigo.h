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
};

#endif // ENEMIGO_H
