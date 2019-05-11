#ifndef PHYSICSSTATE_H
#define PHYSICSSTATE_H
#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;


class PhysicsState
{
public:
    PhysicsState();
    virtual ~PhysicsState();

    sf::Vector2f getPastState();
    sf::Vector2f getActualState();
    sf::Vector2f getVel();
    void setVel(sf::Vector2f newvel);

    void setPastState(sf::Vector2f new_PS);
    void setActualState(sf::Vector2f new_AS);
    void setColliders(vector <sf::Rect<float> > colinit);

    /**TESTER**/
    void drawColliders(sf::RenderWindow *w, double i);
    /**TESTER**/
    vector <sf::Rect<float> > getColliders();

    void Move(sf::Vector2f mover,bool acelerado);//Mueve el objeto que tenga fisicas la distancia pasada por parametro, de forma acelerada o no
    void MoveTo(sf::Vector2f mover_a);//Mueve el objeto a ciertas coordenadas



    void updatePhysicsState(sf::Time et);
    void updateColliders(sf::Vector2f new_pos);

protected:

private:

    sf::Vector2f posNow,posBef;
    sf::Vector2f vel;

    /**Colisionadores**/
    vector < sf::Rect<float> > colliders;
    vector < sf::Rect<float> > initialColliders;

    vector <sf::RectangleShape> boxes;

};

#endif // PHYSICSSTATE_H
