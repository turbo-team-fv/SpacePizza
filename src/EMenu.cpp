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

    menu[0].setFont(font);
    menu[0].setColor(Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(Vector2f(600/2,600/(MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(Vector2f(600/2,600/(MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(Vector2f(600/2,600/(MAX_NUMBER_OF_ITEMS + 1) * 3));

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

    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window->draw(menu[i]);
        }

}

void EMenu::MoveUp(){

    if(selectedItemIndex - 1 >= 0){
        menu[selectedItemIndex].setColor(Color::White);
        selectedItemIndex=selectedItemIndex+1;
        menu[selectedItemIndex].setColor(Color::Red);
    }
}

void EMenu::MoveDown()
{
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setColor(Color::White);
        selectedItemIndex=selectedItemIndex+1;
        menu[selectedItemIndex].setColor(Color::Red);
    }
}

int EMenu::getSelectedItem()
{
    return selectedItemIndex;
}

void EMenu::Init()
{

}

void EMenu::HandleInput()
{

}
void EMenu::Update()
{

}
void EMenu::Draw(float)
{

}
