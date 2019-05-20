#ifndef PUNTUACION_H
#define PUNTUACION_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>"

using namespace sf;

class Puntuacion
{
    public:
        virtual ~Puntuacion();
        static Puntuacion * getInstance();
        void addTiempoParaEntregar(int time);
        void addTiempoEmpleado(int time);
        void calcularPuntuacion();
        void setPizzasEntregadas(int pizzas);
        void addColision();
        void resetPuntuacion();
        int getPuntuacionFinal();
        int getColisiones();
        int getPizzasEntregadas();


    protected:
        Puntuacion();
        Puntuacion(const Puntuacion &);
    private:

        static Puntuacion* pInstancia;
        std::vector<int> tiempoParaentregar;
        std::vector<int> tiempoEmpleado;
        int pizzasEntregadas;
        int puntuacionFinal;
        int numColisionTrafico;
};

#endif // PUNTUACION_H
