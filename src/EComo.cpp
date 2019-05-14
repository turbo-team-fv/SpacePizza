#include "EComo.h"
#include "Juego.h"
#include "EMenu.h"
#include "EJugando.h"
#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

EComo* EComo::EComoInstancia = 0;

EComo* EComo::getInstance()
{
    if(EComoInstancia==0)
    {
        EComoInstancia = new EComo();
    }
    return EComoInstancia;
}

EComo::EComo()
{
    this->Init();
}

void EComo::Init()
{

    numero = -1;
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
    menu[0].setString("Next");
    menu[0].setPosition(Vector2f(150,520));

    menu[1].setCharacterSize(23);
    menu[1].setFont(font);
    menu[1].setColor(Color::White);
    menu[1].setString("Play");
    menu[1].setPosition(Vector2f(500,520));

    selectedItemIndex = 0;

    /**Ejemplo de uso de los sonidos**/
    ControladorSonido::getInstance()->playMusicaMenu();
}

void EComo::Draw(RenderWindow * ventana)
{

    for (int i=0; i< 25; i++)
    {
        if(bg[i]!=NULL)
        {
            if(cambiar)
            {
            cout<<numero<<endl;
                if(numero == 0)
                {
                    ventana->draw(*bg[0]);
                }
                else
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
    }

    for(int i = 0; i < 2; i++)
    {
        ventana->draw(menu[i]);
    }

    ventana->display();
}

void EComo::HandleInputs(Keyboard::Key key, bool isPressed)
{

}

void EComo::Update()
{

}

int EComo::getSelectedItem()
{
    return selectedItemIndex;
}

void EComo::MoveLeft()
{
    if(selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(Color::White);
        selectedItemIndex=selectedItemIndex-1;
        menu[selectedItemIndex].setColor(Color::Cyan);
    }
}

void EComo::MoveRight()
{
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(Color::White);
        selectedItemIndex=selectedItemIndex+1;
        menu[selectedItemIndex].setColor(Color::Cyan);
    }
}

void EComo::HandleEvents(RenderWindow * ventana)
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
                cout<<"Next"<<endl;

                numero++;

                cout<<"numero: "<<numero<<endl;

                cambiar = true;
            }
            else if(selectedItemIndex == 1)
            {
                cout<<"Play"<<endl;
                Juego::getInstance()->cambiarEstado(EJugando::getInstance());
            }
        }
    }
}

void EComo::loop(RenderWindow * ventana, Time timePerFrame)
{
    HandleEvents(ventana);
    ventana->clear();
    Draw(ventana);
}
