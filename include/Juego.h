#ifndef JUEGO_H
#define JUEGO_H
#include "EMenu.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Mundo.h"

using namespace sf;

class Juego
{
public:
    virtual ~Juego();
    static Juego* getInstance();
    void loop();
    void render(double i);//Se le pasa la interpolacion
    void handleEvents();//Recoge el tipo de evento
    void handleInputs(sf::Keyboard::Key key, bool isPressed);
    void updateTime(int change);
    void cambiarEstado(State* state);


protected:
    Juego(); // constructor
    Juego(const Juego &); // operador de copia
    Juego &operator= (const Juego &); // operador de asignacion

private:

    // NEW
    State * estadoActivo;

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

    // int tiempoJuego;
    sf::Clock gameClock;
};

#endif // JUEGO_H
