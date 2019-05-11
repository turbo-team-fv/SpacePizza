#include "PhysicsState.h"

PhysicsState::PhysicsState()
{
    posNow.x=0,posNow.y=0;
    posBef.x=0,posBef.y=0;
    vel.x=0,vel.y=0;

}



sf::Vector2f PhysicsState::getPastState()
{
    return posBef;
}

sf::Vector2f PhysicsState::getActualState()
{
    return posNow;
}

sf::Vector2f PhysicsState::getVel()
{
    return vel;
}

void PhysicsState::setVel(sf::Vector2f newvel){
    vel=newvel;

}

void PhysicsState::setColliders(vector < sf::Rect<float> > colinit)
{

initialColliders=colinit;

    for (unsigned i=0; i< colinit.size(); i++)
    {
        colinit[i].top+=posNow.y;
        colinit[i].left+=posNow.x;

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


void PhysicsState::setActualState(sf::Vector2f new_AS)
{
    posNow=new_AS;
}
void PhysicsState::setPastState(sf::Vector2f new_PS)
{
    posBef=new_PS;
}

void PhysicsState::Move(sf::Vector2f mover, bool acelerado)
{
    int freno=15,limit=150;

    if(acelerado)//MOTOR CON ACELERACION
    {
        if(std::abs(vel.x)<=limit)
        {
            vel.x+=mover.x;
        }
        else
        {
            /**Esta maravilla de aqui devuelve el signo en forma de -1 o 1 : (ax > 0) - (ax < 0)**/
            vel.x=limit*((mover.x > 0) - (mover.x < 0)) ;
        }
        if(std::abs(vel.y)<=limit)
        {
            vel.y+=mover.y;
        }
        else
        {
            vel.y=limit*((mover.y > 0) - (mover.y < 0)) ;
        }


        if (vel.x<=freno&&vel.x>=-freno)
        {
            vel.x = 0.0;
        }
        else
        {
            //decrease the speed
            if(vel.x>freno)
                vel.x -= freno;

            if(vel.x<-7.0)
                vel.x += freno;
        }

        if (vel.y<=freno&&vel.y>=-freno)
        {
            vel.y = 0.0;
        }
        else
        {
            //decrease the speed
            if(vel.y>freno)
                vel.y -= freno;

            if(vel.y<-freno)
                vel.y += freno;
        }
    }
    else//MOTOR SIMPLE
    {

        vel=mover;
    }

}


void PhysicsState::MoveTo(sf::Vector2f mover_a)
{

   colliders=initialColliders;
   posNow=mover_a;
    for(unsigned i = 0; i< colliders.size(); i++){
        colliders[i].top+=posNow.y;
        colliders[i].left+=posNow.x;

    }

}


void PhysicsState::updatePhysicsState(sf::Time et)
{

    posBef=posNow;

    posNow += vel*et.asSeconds();
    //posNow.y += vel.y*et.asSeconds();
    updateColliders(vel*et.asSeconds());

}

void PhysicsState::updateColliders(sf::Vector2f new_pos){


 for(unsigned i=0; i < colliders.size(); i++)
    {
    colliders[i].top+=new_pos.y;
    colliders[i].left+=new_pos.x;


   boxes[i].setPosition(colliders[i].left,colliders[i].top);

    }
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
