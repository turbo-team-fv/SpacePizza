#ifndef MUNDO_H
#define MUNDO_H
#include <vector>
#include <SFML/Graphics.hpp>"
#include <iostream>
#include "Item.h"
#include "Trafico.h"

using namespace std;

class Mundo
{
    public:
        Mundo();
        virtual ~Mundo();
        int getPtoEntregaActual();
        std::vector< sf::Vector2f > getPuntosEntrega();
        std::vector<Item*> getItems();
        std::vector<Trafico*> getTrafico();
        void draw(sf::RenderWindow * window);
        void procesarColisiones();
        void movimientoTrafico();
        sf::Clock getClock();
        sf::Time getTime();
    protected:

    private:
        std::vector< sf::Vector2f > puntosEntrega;
        std::vector< Item* > items;
        std::vector< Trafico* > trafico;
        int ptoEntrgaActual;
        sf::RectangleShape *ptoEntrega;
        sf::Clock clock;
        sf::Time time;
};

#endif // MUNDO_H
