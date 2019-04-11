#ifndef JUEGO_H
#define JUEGO_H

#include "Mapa.h"
#include "EMenu.h"
#include "Jugador.h"
#include "Enemigo.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Mundo.h"

class Juego
{
public:
    virtual ~Juego();
    static Juego* getInstance();
    void loop();
    void render(double i);//Se le pasa la interpolacion
    void updateGameState(sf::Time et);//Recibe el tiempo pasado desde el ultimo update
    void handleEvents();//Recoge el tipo de evento
    void handleInputs(sf::Keyboard::Key key, bool isPressed);


protected:
    Juego(); // constructor
    Juego(const Juego &); // operador de copia
    Juego &operator= (const Juego &); // operador de asignacion

private:

    /**GLOBAL **/
    static const sf::Time	timePerFrame;
    /**GLOBAL **/

    sf::RenderWindow * ventana;

    /** Clock Interpolacion **/
    sf::Clock updateClock;
    sf::Time elapsedTime;
    double interpolation;

    /** Eventos **/
    bool			eUp;
    bool			eDown;
    bool			eRight;
    bool			eLeft;

    static Juego* jInstancia;
    Mapa *mapa;
    Jugador *p1;
    Mundo *mundo;
    Enemigo *e1;

    EMenu * menu;
};

#endif // JUEGO_H
