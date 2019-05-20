#include "EFin.h"
#include "Juego.h"
#include "EMenu.h"
#include "EJugando.h"
#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

EFin* EFin::EFinInstancia = 0;

EFin* EFin::getInstance()
{
    if(EFinInstancia==0)
    {
        EFinInstancia = new EFin();
    }
    return EFinInstancia;
}

EFin::EFin()
{
    this->Init();
}

void EFin::Init()
{
    cout<<"numero: "<<numero<<endl;
    contador = 0;

    if(!font.loadFromFile("assets/hud/m42.TTF"))
    {
        cout<<"Error, no se encuentra la tipografia"<<endl;
    }

    primera = new Texture();
    primera->loadFromFile("assets/howtoplay/1.png");

    segunda = new Texture();
    segunda->loadFromFile("assets/howtoplay/2.png");

    tercera = new Texture();
    tercera->loadFromFile("assets/howtoplay/3.png");

    cuarta = new Texture();
    cuarta->loadFromFile("assets/howtoplay/4.png");

    quinta = new Texture();
    quinta->loadFromFile("assets/howtoplay/5.png");

    sexta = new Texture();
    sexta->loadFromFile("assets/howtoplay/6.png");

    for (int i=0; i<6; i++)
    {
        bg[i] = new Sprite();

        bg[i]->setScale(0.85f,0.85f);
        bg[i]->setPosition(Vector2f(-15,0));
    }

    bg[0]->setTexture(*primera);
    bg[1]->setTexture(*segunda);
    bg[2]->setTexture(*tercera);
    bg[3]->setTexture(*cuarta);
    bg[4]->setTexture(*quinta);
    bg[5]->setTexture(*sexta);

    menu[0].setCharacterSize(23);
    menu[0].setFont(font);
    menu[0].setColor(Color::Cyan);
    menu[0].setString("Exit");
    menu[0].setPosition(Vector2f(150,520));

    menu[1].setCharacterSize(23);
    menu[1].setFont(font);
    menu[1].setColor(Color::White);
    menu[1].setString("Try Again");
    menu[1].setPosition(Vector2f(500,520));

    selectedItemIndex = 0;

    /**Ejemplo de uso de los sonidos**/
    //ControladorSonido::getInstance()->playMusicaMenu();
}

void EFin::Draw(RenderWindow * ventana)
{

    for (int i=0; i< 25; i++)
    {
        if(bg[i]!=NULL)
        {

            if(numero == -1)
            {
                ventana->draw(*bg[0]);
            }
            if(cambiar)
            {
                if(numero == 10)
                {
                    menu[0].setString(" ");
                    menu[1].setString(" ");

                    Juego::getInstance()->cambiarEstado(EMenu::getInstance());

                }
                ventana->draw(*bg[numero-(numero/2)]);
            }
        }
    }

    for(int i = 0; i < 2; i++)
    {
        ventana->draw(menu[i]);
    }

    ventana->display();
}

void EFin::HandleInputs(Keyboard::Key key, bool isPressed)
{

}

void EFin::Update()
{

}

int EFin::getSelectedItem()
{
    return selectedItemIndex;
}

void EFin::MoveLeft()
{
    if(selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(Color::White);
        selectedItemIndex=selectedItemIndex-1;
        menu[selectedItemIndex].setColor(Color::Cyan);
    }
}

void EFin::MoveRight()
{
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(Color::White);
        selectedItemIndex=selectedItemIndex+1;
        menu[selectedItemIndex].setColor(Color::Cyan);
    }
}

void EFin::HandleEvents(RenderWindow * ventana)
{
    Event event;
    if (ventana->pollEvent(event))
    {
        Keyboard e;

        if(e.isKeyPressed(Keyboard::Right))
        {
            MoveRight();
        }

        if(e.isKeyPressed(Keyboard::Left))
        {
            MoveLeft();
        }

        if (e.isKeyPressed(Keyboard::Return))
        {
            cout<<"SelectedItemIndex"<<selectedItemIndex<<endl;
            if(selectedItemIndex == 0)
            {
               EMenu::getInstance()->Init();
                Juego::getInstance()->cambiarEstado(EMenu::getInstance());
                ControladorSonido::getInstance()->playMusicaMenu();
                 ventana->close();
            }
            else if(selectedItemIndex == 1)
            {
                cout<<"Play"<<endl;

                EJugando::getInstance()->Init();
                Juego::getInstance()->cambiarEstado(EJugando::getInstance());
                ControladorSonido::getInstance()->playRadio(0);

            }
        }
    }
}

void EFin::loop(RenderWindow * ventana, Time timePerFrame)
{
    HandleEvents(ventana);
    ventana->clear();
    Draw(ventana);
}
