#include "EFin.h"
#include "Juego.h"
#include "EMenu.h"
#include "EJugando.h"
#include "Puntuacion.h"
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
    /*cout<<"numero: "<<numero<<endl;
    contador = 0;
    /// NOTA=> Como acceder a la puntuacion
    Puntuacion::getInstance()->calcularPuntuacion();
    int puntuacionTotal = Puntuacion::getInstance()->getPuntuacionFinal();
    int pizzasEntregadas = Puntuacion::getInstance()->getPizzasEntregadas();
    int colisionesTrafico = Puntuacion::getInstance()->getColisiones();
    cout<<"Puntuacion final: " << puntuacionTotal<<std::endl;
    cout<<"Pizzas entregadas: " <<pizzasEntregadas<<std::endl;
    cout<<"Colisiones con el trafico: "<< colisionesTrafico<<std::endl;*/
    /// TODO => falta resetear la posicion cuando vuelves a empezar partida => Puntuacion::getInstance()->resetPuntuacion()

    if(!font.loadFromFile("assets/hud/m42.TTF"))
    {
        cout<<"Error, no se encuentra la tipografia"<<endl;
    }

    primera = new Texture();
    primera->loadFromFile("assets/hud/points.png");



    for (int i=0; i<6; i++)
    {
        bg[i] = new Sprite();

        bg[i]->setScale(0.42f,0.40f);
        bg[i]->setPosition(Vector2f(-15,0));
    }

    bg[0]->setTexture(*primera);


    menu[0].setCharacterSize(23);
    menu[0].setFont(font);
    menu[0].setColor(Color::Cyan);
    menu[0].setString("Exit");
    menu[0].setPosition(Vector2f(260,490));

    menu[1].setCharacterSize(23);
    menu[1].setFont(font);
    menu[1].setColor(Color::White);
    menu[1].setString("Try Again");
    menu[1].setPosition(Vector2f(260,540));

    puntuacion.setCharacterSize(25);
    puntuacion.setFont(font);
    puntuacion.setColor(Color::Yellow);
    puntuacion.setString("Puntuacion");
    puntuacion.setPosition(Vector2f(250,220));

    estilo.setCharacterSize(21);
    estilo.setFont(font);
    estilo.setColor(Color::Red);
    estilo.setString("Estilo");
    estilo.setPosition(Vector2f(250,260));

    pizzas.setCharacterSize(21);
    pizzas.setFont(font);
    pizzas.setColor(Color::Green);
    pizzas.setString("Pizzas");
    pizzas.setPosition(Vector2f(250,300));

    selectedItemIndex = 0;


    //in_puntos= Puntuacion::getInstance()->getPuntuacionFinal();
    in_puntos=0;
    in_estilo=0;
    in_pizzas=0;
    out_pizzas=0,out_puntos=0,out_estilo=0;



    /**Ejemplo de uso de los sonidos**/
    //ControladorSonido::getInstance()->playMusicaMenu();
}

void EFin::restartRank(){
  Puntuacion::getInstance()->calcularPuntuacion();
in_puntos=Puntuacion::getInstance()->getPuntuacionFinal();
    in_estilo=Puntuacion::getInstance()->getColisiones();
    in_pizzas=Puntuacion::getInstance()->getPizzasEntregadas();

    cout<<"Estilo: "<<in_estilo<<endl;
    cout<<"Puntos: "<<in_puntos<<endl;
    cout<<"pizzas: "<<in_pizzas<<endl;
out_pizzas=0,out_puntos=0,out_estilo=0;
ControladorSonido::getInstance()->playFin();
}

void EFin::Draw(RenderWindow * ventana)
{


    ventana->draw(*bg[0]);
    for(int i = 0; i < 2; i++)
    {
        ventana->draw(menu[i]);
    }



    std::stringstream ss;
    ss << out_puntos;
    s_puntos = "POINTS: ";
    s_puntos += ss.str();
    puntuacion.setString(s_puntos);



    s_estilo = "STYLE: ";
    if(in_estilo>100){
    s_estilo += "SO BAD";
        estilo.setColor(Color::Red);
    }else if(in_estilo<100&&in_estilo>65){
    s_estilo += "CLUMSY";
        estilo.setColor(Color::Magenta);
    }
    else if(in_estilo<65&&in_estilo>40){
    s_estilo += "GOOD";
    estilo.setColor(Color::Yellow);
    }
     else if(in_estilo<40&&in_estilo>5){
    s_estilo += "COOL RIDER";
    estilo.setColor(Color::Green);
    }
    else if(in_estilo<5){
    s_estilo += "PERFECT!!";
    estilo.setColor(Color::Cyan);
    }


    //s_estilo += ss1.str();
    estilo.setString(s_estilo);
    std::stringstream ss2;
    ss2 << out_pizzas;
    s_pizzas = "PIZZAS: ";
    s_pizzas += ss2.str();
    pizzas.setString(s_pizzas);

    ventana->draw(puntuacion);
    ventana->draw(estilo);
    ventana->draw(pizzas);



    if(dibujado.getElapsedTime().asMilliseconds()>10)
    {
        if(out_puntos<=in_puntos)
        {
            out_puntos+=1;
        }
        /*if(out_estilo<=in_estilo)
        {
            out_estilo+=10;
        }*/
        if(out_pizzas<=in_pizzas)
        {
            out_pizzas+=1;
        }
        dibujado.restart();
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
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS-1)
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

        if(e.isKeyPressed(Keyboard::Up))
        {
            MoveLeft();
        }

        if(e.isKeyPressed(Keyboard::Down))
        {
            MoveRight();
        }

        if (e.isKeyPressed(Keyboard::Return))
        {


            cout<<"SelectedItemIndex"<<selectedItemIndex<<endl;
            if(selectedItemIndex == 0)
            {

                ventana->close();

            }
            else if(selectedItemIndex == 1)
            {
                cout<<"Play"<<endl;

                EJugando::getInstance()->Init();
                Juego::getInstance()->cambiarEstado(EJugando::getInstance());
                ControladorSonido::getInstance()->playRadio(0);
                ControladorSonido::getInstance()->stopFin();

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
