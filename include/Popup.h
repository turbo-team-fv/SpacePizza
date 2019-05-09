#ifndef POPUP_H
#define POPUP_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SuperSprite.h"


class Popup
{
    public:
        Popup(string ruta, int life);
        void setLife(int t);
        SuperSprite* getSprite();
        void setPosition(double x, double y);
        void drawPopup(sf::RenderWindow *w, double i);
        void throwPopup();


        virtual ~Popup();


    protected:

    private:
    SuperSprite* popup;
    sf::Clock popup_clock;
    int popup_life;
    bool alive;
    vector <double> pos;
};

#endif // POPUP_H
