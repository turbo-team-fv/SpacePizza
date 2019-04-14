#ifndef EJUGANDO_H
#define EJUGANDO_H
#include "State.h"
#include "Juego.h"

class EJugando : public State
{
    public:
        static EJugando * getInstance();
        void Init();
        void HandleInput(RenderWindow * ventana);
        void Update();
        void Draw(RenderWindow * ventana);

    protected:
        EJugando(); // constructor
        EJugando(const EJugando &); // operador de copia
        EJugando &operator= (const EJugando &); // operador de asignacion

    private:
        static EJugando * eJugandoInstancia;

        Juego * SpacePizza;
};

#endif // EJUGANDO_H
