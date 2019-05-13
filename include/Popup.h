#ifndef POPUP_H
#define POPUP_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SuperSprite.h"


class Popup
{
    public:
        Popup(string ruta, double life);
        void setLife(double t);
        SuperSprite* getSprite();
        void setPosition(sf::Vector2f new_pos);
        void drawPopup(sf::RenderWindow *w, double i);
        void throwPopup();


        virtual ~Popup();


    protected:

    private:
    SuperSprite* popup;
    sf::Clock popup_clock;
    double popup_life;
    bool alive;
    sf::Vector2f pos;
};

#endif // POPUP_H
