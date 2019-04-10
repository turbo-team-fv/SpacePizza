#ifndef PHYSICSSTATE_H
#define PHYSICSSTATE_H
#include <iostream>
#include <vector>
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

    void setPastState(double x, double y);
    void setActualState(double x, double y);

    void Move(double ax,double ay,bool acelerado);//Mueve el objeto que tenga fisicas la distancia pasada por parametro, de forma acelerada o no
    void MoveTo(double ax,double ay);//Mueve el objeto a ciertas coordenadas


    void updatePhysicsState(sf::Time et);

protected:

private:

    vector<double> posNow,posBef;
    vector<double> vel;

};

#endif // PHYSICSSTATE_H