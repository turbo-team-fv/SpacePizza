#include "Popup.h"

Popup::Popup(string ruta, double life)
{
    //ctor
    pos.push_back(0);
    pos.push_back(0);
    popup=new SuperSprite(ruta,1,0.5,true);

    popup->setSpeed(0.1);
    popup->setAnimation(0);
    setLife(life);
    alive=false;
}

void Popup::setLife(double t)
{
    popup_life=t;
}
SuperSprite* Popup::getSprite()
{
    return popup;
}
 void Popup::setPosition(double x, double y){

 pos[0]=x;
 pos[1]=y;
 }
void Popup::throwPopup()
{

    popup_clock.restart();
    alive=true;
}

void Popup::drawPopup(sf::RenderWindow *w, double i)
{
    if(popup_clock.getElapsedTime().asSeconds()<popup_life&&alive)
    {
        this->popup->drawSuperSprite(pos,pos,w,i);
    }
    if(popup_clock.getElapsedTime().asSeconds()>popup_life){
    alive=false;
    }
}

Popup::~Popup()
{
    //dtor
}
