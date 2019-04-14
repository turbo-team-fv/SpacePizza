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



    void colisionesMapa();
    void procesarColisiones();

    void processHUD();
protected:

private:

    int ptoEntrgaActual;
    sf::RectangleShape *ptoEntrega;

    /** vista, minimap & HUD stuff **/
    sf::View * vista, * minimap; // La super vista y el super minimapa
    int player_lifes, num_pizzas;
    Font * font_player_lifes, *font_numbers;
    Text * text_player_lifes, *text_num_pizzas, *text_time;
    Texture * txt_pizza;
    Sprite * spr_pizza;



    /**ELEMENTOS**/
    vector< sf::Vector2f > puntosEntrega;
    vector< Item* > items;
    Mapa *mapa;
    Jugador *p1;
    Enemigo *e1;
    /**ELEMENTOS**/

};

#endif // MUNDO_H
