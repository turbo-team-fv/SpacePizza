#ifndef EJUGANDO_H
#define EJUGANDO_H
#include "State.h"
#include "Juego.h"
#include "SFML/Graphics.hpp"
#include "Puntuacion.h"

class EJugando : public State
{
    public:
        static EJugando * getInstance();

        void loop(RenderWindow * ventana, sf::Time timePerFrame);
        void render(double i, RenderWindow * ventana, Time timePerFrame);//Se le pasa la interpolacion
        void updateGameState(bool eRight,bool eLeft,bool eUp,bool eDown,bool godMode, sf::Time et);//Recibe el tiempo pasado desde el ultimo update
        void HandleInputs(sf::Keyboard::Key key, bool isPressed);

        /**STATE**/
        void Init();
        void HandleEvents(RenderWindow * window);
        void Update();

        void Draw(RenderWindow * ventana);

    protected:
        EJugando(); // constructor
        EJugando(const EJugando &); // operador de copia
        EJugando &operator= (const EJugando &); // operador de asignacion

    private:

        /** Clock Interpolacion **/
        Clock updateClock;
        Time elapsedTime;
        double interpolation;

        /** Eventos **/
        bool eUp;
        bool eDown;
        bool eRight;
        bool eLeft;
        bool godMode;

        static EJugando * eJugandoInstancia;

        Mundo *mundo;
        EMenu * menu;
};

#endif // EJUGANDO_H
