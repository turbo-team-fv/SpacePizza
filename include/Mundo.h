#ifndef MUNDO_H
#define MUNDO_H
#include <vector>
#include <SFML/Graphics.hpp>"
#include <iostream>
#include "Item.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Mapa.h"

using namespace std;

class Mundo
{
    public:
        Mundo();
        virtual ~Mundo();
        int getPtoEntregaActual();
        vector< sf::Vector2f > getPuntosEntrega();
        vector<Item*> getItems();

        void updateMundo(double x, double y, sf::Time t);
        void drawMundo(sf::RenderWindow * window, double i);
        void procesarColisiones();
    protected:

    private:

        int ptoEntrgaActual;
        sf::RectangleShape *ptoEntrega;

        /**ELEMENTOS**/
        vector< sf::Vector2f > puntosEntrega;
        vector< Item* > items;
        Mapa *mapa;
        Jugador *p1;
        Enemigo *e1;
        /**ELEMENTOS**/

};

#endif // MUNDO_H
