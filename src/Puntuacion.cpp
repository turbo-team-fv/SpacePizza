#include "Puntuacion.h"

Puntuacion::Puntuacion()
{
    //ctor
    numColisionTrafico = 0;
    puntuacionFinal = 0;
    tiempoEmpleado =  std::vector<int>();
    tiempoEmpleado =  std::vector<int>();
}

Puntuacion* Puntuacion::pInstancia = 0;

Puntuacion * Puntuacion::getInstance(){
    if(pInstancia == 0) {
        pInstancia = new Puntuacion();
    }

    return pInstancia;
}
void  Puntuacion::addTiempoParaEntregar(int time)  {
    std::cout<<"Añado el tiempo que me dan para entregar una pizza"<<std::endl;
    tiempoParaentregar.push_back(time);
}

void Puntuacion::addTiempoEmpleado(int time) {
    std::cout<<"Añado el tiempo empleado en entregar una pizza"<<std::endl;
    std::cout<<time<<std::endl;
    tiempoEmpleado.push_back(time);
}
/// Metodo que calcula la puntuacion en funcion de los tiempos empleados y los tiempos que me dan para
/// entregar la pizza y le resta una penalizacion por colisiones
/// TODO => Revisar esta parte a la hora de reiniciar los valores de puntuacion
void Puntuacion::calcularPuntuacion(){
    int ptoXpizza = 100;
    for(int i = 0; i < tiempoEmpleado.size(); i++ ){
           float aux = (tiempoParaentregar[i]) / (tiempoEmpleado[i]);
           puntuacionFinal += aux*ptoXpizza;
    }
    /// Penalizacion por colisiones con los coches
    puntuacionFinal -= numColisionTrafico * 5;
    std::cout<<"Puntuacion final"<<std::endl;
    std::cout<<puntuacionFinal<<std::endl;
    if(puntuacionFinal <= 0 ){
        puntuacionFinal = 0;
    }
}
void Puntuacion::setPizzasEntregadas(int pizzas) {
    pizzasEntregadas = pizzas;
}
int Puntuacion::getPuntuacionFinal() {
    return puntuacionFinal;
}

void Puntuacion::addColision(){
    numColisionTrafico++;
    std::cout<<"Aumento una colison con el trafico"<<std::endl;
    std::cout<<numColisionTrafico<<std::endl;
}

void Puntuacion::resetPuntuacion() {
    numColisionTrafico = 0;
    puntuacionFinal = 0;
    tiempoEmpleado =  std::vector<int>();
    tiempoEmpleado =  std::vector<int>();

}

int Puntuacion::getPizzasEntregadas() {
    return pizzasEntregadas;
}

int Puntuacion::getColisiones() {
    return numColisionTrafico;
}
Puntuacion::~Puntuacion()
{
    //dtor
}
