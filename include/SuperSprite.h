#ifndef SUPERSPRITE_H
#define SUPERSPRITE_H
#include "PhysicsState.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;


class SuperSprite
{
    public:
        SuperSprite(string ruta, int numanim, double escala, bool animado);
        void addFrame(sf::IntRect frame,int animation);
        void setSpeed(double s);
        void setAnimation(int a);
        sf::Sprite* getActualSprite();
        vector<double> getRenderPos();
        void calcInter(vector<double> past, vector<double> actual,sf::RenderWindow *w, double i);
        void drawSuperSprite(vector<double> past, vector<double> actual,sf::RenderWindow *w, double i);
        virtual ~SuperSprite();

    protected:

    private:

    sf::Texture *textura;
    sf::Sprite *s_sprite;
    sf::Clock changer;
    vector < vector < sf::Rect <int> > > frames; ///Matriz de frames

    int animacion;
    int frame;

    double speed;
    int numeroAnimaciones;
    bool animado;

    vector<double> renderPos;


};

#endif // SUPERSPRITE_H
