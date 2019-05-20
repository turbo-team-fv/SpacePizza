#ifndef PUNTUACION_H
#define PUNTUACION_H
#include <iostream>
#include <vector>


using namespace sf;

class Puntuacion
{
    public:
        virtual ~Puntuacion();
        static Puntuacion * getInstance();

    protected:
        Puntuacion();
        Puntuacion(const Puntuacion &);
    private:
        std::vector<float> tiempoParaentregar;
        std::vector<float> tiempoEmpleado;


};

#endif // PUNTUACION_H
