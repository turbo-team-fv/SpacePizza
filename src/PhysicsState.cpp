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

vector<double> PhysicsState::getVel()
{
    return vel;
}

void PhysicsState::setVel(double x, double y){
    vel[0]=x,vel[1]=y;

}

void PhysicsState::setColliders(vector < sf::Rect<float> > colinit)
{


    for (unsigned i=0; i< colinit.size(); i++)
    {
        colinit[i].top+=posNow[1];
        colinit[i].left+=posNow[0];

        boxes.push_back(sf::RectangleShape(sf::Vector2f(colinit[i].width,colinit[i].height)));


        boxes[i].setFillColor(sf::Color(i*50, i*50, i*50));
        boxes[i].setPosition(colinit[i].left,colinit[i].top);

        colliders.push_back(colinit[i]);


    }


}
vector <sf::Rect<float> >  PhysicsState::getColliders()
{
    return colliders;
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
        if(std::abs(vel[0])<=limit)
        {
            vel[0]+=ax;
        }
        else
        {
            /**Esta maravilla de aqui devuelve el signo en forma de -1 o 1 : (ax > 0) - (ax < 0)**/
            vel[0]=limit*((ax > 0) - (ax < 0)) ;
        }
        if(std::abs(vel[1])<=limit)
        {
            vel[1]+=ay;
        }
        else
        {
            vel[1]=limit*((ay > 0) - (ay < 0)) ;
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

    posNow[0]=ax,posNow[1]=ay;
    posBef=posNow;
}

void PhysicsState::updatePhysicsState(sf::Time et)
{

    posBef=posNow;

    posNow[0] += vel[0]*et.asSeconds();
    posNow[1] += vel[1]*et.asSeconds();

    for(unsigned i=0; i < colliders.size(); i++)
    {
    colliders[i].top+= vel[1]*et.asSeconds();
    colliders[i].left+= vel[0]*et.asSeconds();
    /*colliders[i].left=posNow[0];
    colliders[i].top=posNow[1];*/

    boxes[i].setPosition(colliders[i].left,colliders[i].top);

    }

//    cout << "POSICION ACTUAL" << posNow[0] << ", " << posNow[1] << endl;

}

void PhysicsState::drawColliders(sf::RenderWindow *w, double i)
{

    for(unsigned i=0; i < boxes.size(); i++)
    {
        w->draw(boxes[i]);
    }

}


PhysicsState::~PhysicsState()
{
    //dtor
}
