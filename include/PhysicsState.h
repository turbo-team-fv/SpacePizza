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

    vector<double> getPastState();
    vector<double> getActualState();
    vector<double> getVel();
    void setVel(double x, double y);

    void setPastState(double x, double y);
    void setActualState(double x, double y);
    void setColliders(vector <sf::Rect<float> > colinit);

    /**TESTER**/
    void drawColliders(sf::RenderWindow *w, double i);
    /**TESTER**/
    vector <sf::Rect<float> > getColliders();

    void Move(double ax,double ay,bool acelerado);//Mueve el objeto que tenga fisicas la distancia pasada por parametro, de forma acelerada o no
    void MoveTo(double ax,double ay);//Mueve el objeto a ciertas coordenadas
    void MovePlayerTo(double ax,double ay, sf::Time et);


    void updatePhysicsState(sf::Time et);

protected:

private:

    vector<double> posNow,posBef;
    vector<double> vel;

    /**Colisionadores**/
    vector < sf::Rect<float> > colliders;

    vector <sf::RectangleShape> boxes;

};

#endif // PHYSICSSTATE_H
