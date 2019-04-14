#include "Juego.h"
#include "Motor2D.h"
#include "State.h"

using namespace std;


int main(int argc, char *argv[])
{
//    Juego * SpacePizza = Juego::getInstance(); //Asi se crea con el singleton
//    SpacePizza->loop();
//    return 0;

    Motor2D* motor = Motor2D::Instance();
    State* menu = EMenu::getInstance();
    Juego* j = Juego::getInstance();
    j->setState(menu);
    j->loop();

    return 0;
}

