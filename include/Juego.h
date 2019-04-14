#ifndef JUEGO_H
#define JUEGO_H
#include "EMenu.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Mundo.h"
#include "State.h"

using namespace sf;

class Juego
{
public:
    virtual ~Juego();
    static Juego* getInstance();
    void loop();
    void render(double i);//Se le pasa la interpolacion
    void updateGameState(bool eRight,bool eLeft,bool eUp,bool eDown, sf::Time et);//Recibe el tiempo pasado desde el ultimo update
    void handleEvents();//Recoge el tipo de evento
    void setState(State* escena);

protected:
    Juego(); // constructor
    Juego(const Juego &); // operador de copia
    Juego &operator= (const Juego &); // operador de asignacion

private:

    /**GLOBAL **/
    static const sf::Time	timePerFrame;
    /**GLOBAL **/

    RenderWindow * ventana;

    /** Clock Interpolacion **/
    Clock updateClock;
    Time elapsedTime;
    double interpolation;

    /** Eventos **/
    bool eUp;
    bool eDown;
    bool eRight;
    bool eLeft;

    static Juego* jInstancia;

    Mundo *mundo;
    EMenu * menu;

    State* escena;
};

#endif // JUEGO_H
