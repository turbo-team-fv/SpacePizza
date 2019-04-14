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

        void updateMundo(bool eRight, bool eLeft, bool eUp, bool eDown, sf::Time t);
        void drawMundo(sf::RenderWindow * window, double i);
        void procesarColisiones();
        void initPuntosEntrega();
        void initItems();
        int getTime();
    protected:

    private:

        int ptoEntrgaActual;
        //sf::RectangleShape *ptoEntrega;

        /**ELEMENTOS**/
        vector< sf::Vector2f > puntosEntrega;
        vector< Item* > items;
        Mapa *mapa;
        Jugador *p1;
        Enemigo *e1;
        /**ELEMENTOS**/

        int pizzas;
        int tiempo;

        sf::Texture texture;
        sf::Sprite *puntoEntrega;

};

#endif // MUNDO_H
