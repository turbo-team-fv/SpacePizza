#include "PhysicsState.h"

PhysicsState::PhysicsState()
{
    posNow.push_back(0.0),posNow.push_back(0.0);
    posBef.push_back(0.0),posBef.push_back(0.0);
    vel.push_back(0.0),vel.push_back(0.0);
}



vector<double> PhysicsState::getPastState()
{
    return posBef;
}

vector<double> PhysicsState::getActualState()
{
    return posNow;
}


void PhysicsState::setActualState(double x, double y)
{
    posNow[0]=x,posNow[1]=y;
}
void PhysicsState::setPastState(double x, double y)
{
    posBef[0]=x,posBef[1]=y;
}

void PhysicsState::Move(double ax, double ay, bool acelerado)
{
    int freno=15,limit=150;

    if(acelerado)//MOTOR CON ACELERACION
    {
        if(vel[0]<limit)
        {
            vel[0]+=ax;
        }
        else
        {
            vel[0]=limit;
        }
        if(vel[1]<limit)
        {
            vel[1]+=ay;
        }
        else
        {
            vel[1]=limit;
        }


        if (vel[0]<=freno&&vel[0]>=-freno)
        {
            vel[0] = 0.0;
        }
        else
        {
            //decrease the speed
            if(vel[0]>freno)
                vel[0] -= freno;

            if(vel[0]<-7.0)
                vel[0] += freno;
        }

        if (vel[1]<=freno&&vel[1]>=-freno)
        {
            vel[1] = 0.0;
        }
        else
        {
            //decrease the speed
            if(vel[1]>freno)
                vel[1] -= freno;

            if(vel[1]<-freno)
                vel[1] += freno;
        }
    }
    else//MOTOR SIMPLE
    {

        vel[0]=ax;
        vel[1]=ay;
    }

}

void PhysicsState::MoveTo(double ax,double ay)
{

}

void PhysicsState::updatePhysicsState(sf::Time et)
{

    posBef=posNow;

    posNow[0] += vel[0]*et.asSeconds();
    posNow[1] += vel[1]*et.asSeconds();

}



PhysicsState::~PhysicsState()
{
    //dtor
}
