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

    menu.setCharacterSize(23);
    menu.setFont(font);
    menu.setColor(Color::Cyan);
    menu.setString("Next");
    menu.setPosition(Vector2f(320,520));

    selectedItemIndex = 0;

    /**Ejemplo de uso de los sonidos**/
    ControladorSonido::getInstance()->playMusicaMenu();
}

void EComo::Draw(RenderWindow * ventana)
{

    for (int i = 0; i < 6; i++)
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
                    menu.setString("");
                    Juego::getInstance()->cambiarEstado(EMenu::getInstance());
                }
                else
                {
                    ventana->draw(*bg[numero-(numero/2)]);
                }
            }
        }
        ventana->draw(menu);
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

void EComo::HandleEvents(RenderWindow * ventana)
{
    Event event;
    if (ventana->pollEvent(event))
    {
        Keyboard e;

        if (e.isKeyPressed(Keyboard::Return))
        {
            if(selectedItemIndex == 0)
            {
                numero++;
                cambiar = true;
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
