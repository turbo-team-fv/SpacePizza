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
    tiempoEmpleado.push_back(time);
}
/// Metodo que calcula la puntuacion en funcion de los tiempos empleados y los tiempos que me dan para
/// entregar la pizza y le resta una penalizacion por colisiones
/// TODO => Revisar esta parte a la hora de reiniciar los valores de puntuacion
void Puntuacion::calcularPuntuacion(){
    int ptoXpizza = 100;
    for(int i = 0; i < tiempoEmpleado.size(); i++ ){
           float aux = ((float)(tiempoParaentregar[i]) / (float)(tiempoEmpleado[i])) * ptoXpizza;
           if(aux > ptoXpizza) { /// Para que como maximo una pizza solo pueda dar 100 puntos
            aux = ptoXpizza;
           }
           puntuacionFinal += aux;
    }
    /// Penalizacion por colisiones con los coches
    puntuacionFinal -= numColisionTrafico;
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
    std::cout<<"Añado colison con el trafico"<<std::endl;
    numColisionTrafico++;
    std::cout<<numColisionTrafico<<std::endl;
}

void Puntuacion::resetPuntuacion() {
    numColisionTrafico = 0;
    puntuacionFinal = 0;
    pizzasEntregadas = 0;
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
