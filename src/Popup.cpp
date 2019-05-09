#include "Popup.h"

Popup::Popup(string ruta, int life)
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

void Popup::setLife(int t)
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
cout<<"Pop up generado"<<endl;
    popup_clock.restart();
    alive=true;
}

void Popup::drawPopup(sf::RenderWindow *w, double i)
{
    if(popup_clock.getElapsedTime().asSeconds()<popup_life&&alive)
    {
        this->popup->drawSuperSprite(pos,pos,w,i);
        cout<<"Pop up esta vivo y lo dibujo en: "<<pos[0]<<" , "<<pos[1]<<endl;
    }
    if(popup_clock.getElapsedTime().asSeconds()>popup_life){
    alive=false;
    }
}

Popup::~Popup()
{
    //dtor
}
