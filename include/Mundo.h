#ifndef MUNDO_H
#define MUNDO_H
#include <vector>
#include <SFML/Graphics.hpp>"
#include <iostream>
#include "Item.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Mapa.h"
#include "SuperSprite.h"
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

    void updateMundo(bool eRight, bool eLeft, bool eUp, bool eDown, sf::Time t);
    void drawMundo(sf::RenderWindow * window, double i);
    void drawItems(sf::RenderWindow * window);
    void drawAlcantarillas(sf::RenderWindow * window);
    int getTime();
    void initItems();
    void initPuntosEntrega();
    void colisionesMapa();
        void colisionAlcantarilla(bool eRight, bool eLeft, bool eUp, bool eDown);
        void procesarColisiones(bool eRight, bool eLeft, bool eUp, bool eDown);
        void initAlcantarillas();



    void visionIA();
    void colisionesMapa();
    void procesarColisiones();
        vector< Alcantarilla *> alcantarillas;

    void processHUD();
protected:

private:

    int ptoEntrgaActual;
    sf::RectangleShape *ptoEntrega;

    /** vista, minimap & HUD stuff **/
    sf::View * vista, * minimap, *vista_hud; // La super vista y el super minimapa
    int player_lifes, num_pizzas;
    Texture * txt_pizza;
    Sprite * spr_pizza;


    /**ELEMENTOS**/
    vector< sf::Vector2f > puntosEntrega;
    vector< Item* > items;
    Mapa *mapa;
    Jugador *p1;
    vector< Enemigo* > e1;
    /**ELEMENTOS**/

    int pizzas;
    int tiempo;
    sf::Sprite *puntoEntrega;
    sf::Texture texture;
};

#endif // MUNDO_H
