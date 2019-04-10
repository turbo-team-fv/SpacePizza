#include "Juego.h"
using namespace std;


int main(int argc, char *argv[])
{
    Juego * SpacePizza = Juego::getInstance(); //Asi se crea con el singleton
    SpacePizza->loop();
    return 0;
}

