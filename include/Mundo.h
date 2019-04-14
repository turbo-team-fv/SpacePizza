#ifndef MUNDO_H
#define MUNDO_H
#include <vector>
#include <SFML/Graphics.hpp>"
#include <iostream>
#include "Item.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Mapa.h"
#include "Alcantarilla.h"

using namespace std;

class Mundo
{
    public:
        Mundo();
        virtual ~Mundo();
        int getPtoEntregaActual();
        vector< sf::Vector2f > getPuntosEntrega();
        vector<Item*> getItems();

        void drawPuntosEntrega(sf::RenderWindow * window);
        void drawItems(sf::RenderWindow * window);
        void drawAlcantarillas(sf::RenderWindow * window);

        void updateMundo(bool eRight, bool eLeft, bool eUp, bool eDown, sf::Time t);
        void drawMundo(sf::RenderWindow * window, double i);

        /**COLISIONES**/
        void colisionAlcantarilla(bool eRight, bool eLeft, bool eUp, bool eDown);
        void procesarColisiones(bool eRight, bool eLeft, bool eUp, bool eDown);
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
        vector< Alcantarilla *> alcantarillas;
        /**ELEMENTOS**/

};

#endif // MUNDO_H
