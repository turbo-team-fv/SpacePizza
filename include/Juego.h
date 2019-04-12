#ifndef JUEGO_H
#define JUEGO_H
#include "EMenu.h"
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
    void updateGameState(bool eRight,bool eLeft,bool eUp,bool eDown, sf::Time et);//Recibe el tiempo pasado desde el ultimo update
    void handleEvents();//Recoge el tipo de evento
    void handleInputs(sf::Keyboard::Key key, bool isPressed);
    void processHUD();

protected:
    Juego(); // constructor
    Juego(const Juego &); // operador de copia
    Juego &operator= (const Juego &); // operador de asignacion

private:

    /**GLOBAL **/
    static const sf::Time	timePerFrame;
    /**GLOBAL **/

    sf::RenderWindow * ventana;

    sf::View * vista, * minimap; // La super vista y el super minimapa

    /** HUD stuff **/
    int player_lifes, num_pizzas;
    Texture * txt_pizza;
    Sprite * spr_pizza;

    /** Clock Interpolacion **/
    sf::Clock updateClock;
    sf::Time elapsedTime;
    double interpolation;

    /** Eventos **/
    bool eUp;
    bool eDown;
    bool eRight;
    bool eLeft;

    static Juego* jInstancia;

    Mundo *mundo;
    EMenu * menu;
};

#endif // JUEGO_H
