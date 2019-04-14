#include "Motor2D.h"
#include "Juego.h"
#include <iostream>

Motor2D* Motor2D::pinstance = 0;
Motor2D* Motor2D::Instance()
{
    if(pinstance == 0){
        pinstance = new Motor2D();
    }

    return pinstance;
}

Motor2D::Motor2D()
    :window(VideoMode(600,600), "SpacePizza"){}

void Motor2D::dibujar(Sprite spri){
    window.draw(spri);
}

bool Motor2D::openWindow(){
    window.isOpen();
}

void Motor2D::clearWindow(){
    window.clear();
}

void Motor2D::displayWindow(){
    window.display();
}

void Motor2D::closeWindow(){
    window.close();
}

void Motor2D::setCamera(){

   // window.setView(cam.getView());
}

void Motor2D::setFrameLimit(){
    window.setFramerateLimit(60);
}

void Motor2D::resetCamera(){
    window.setView(window.getDefaultView());
}

RenderWindow* Motor2D::getWindow(){
    return &window;
}








