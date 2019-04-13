#include "EMenu.h"
#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

EMenu::EMenu()
{
    if(!font.loadFromFile("assets/PressStart2P.ttf")){
        cout<<"Error, no se encuentra la tipografia"<<endl;
    }

    bgMenu_txt = new Texture();

    if(!bgMenu_txt->loadFromFile("assets/hud/SpacePizzaSplashScreen.jpg")){
        cout<<"Error, no se encuentra la imagen SpacePizzaSplashScreen"<<endl;
    }

    bg_menu = new Sprite(*bgMenu_txt);
    bg_menu->setScale(0.4f,0.4f);

    menu[0].setFont(font);
    menu[0].setColor(Color::Cyan);
    menu[0].setString("Play");
    menu[0].setPosition(Vector2f(675/2,1300/(MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(Color::White);
    menu[1].setString("How to play");
    menu[1].setPosition(Vector2f(480/2,800/(MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(Vector2f(680/2,650/(MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}

EMenu* EMenu::eMenuInstancia = 0;

EMenu* EMenu::getInstance()
{
    if(eMenuInstancia==0)
    {
        eMenuInstancia = new EMenu();
    }

    return eMenuInstancia;
}

void EMenu::draw(RenderWindow * window){

    window->draw(*bg_menu);

    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window->draw(menu[i]);
        }

}

void EMenu::MoveUp(){

    if(selectedItemIndex - 1 >= 0){
        menu[selectedItemIndex].setColor(Color::White);
        selectedItemIndex=selectedItemIndex-1;
        menu[selectedItemIndex].setColor(Color::Cyan);
    }
}

void EMenu::MoveDown(){

    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setColor(Color::White);
        selectedItemIndex=selectedItemIndex+1;
        menu[selectedItemIndex].setColor(Color::Cyan);
    }
}

int EMenu::getSelectedItem(){
    return selectedItemIndex;
}
