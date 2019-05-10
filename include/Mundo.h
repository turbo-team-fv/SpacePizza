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
#include "Popup.h"
#include <sstream>
#include <iomanip>

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
    sf::Vector2f colisionesMapa();
    void colisionAlcantarilla(bool eRight, bool eLeft, bool eUp, bool eDown);
    void colisionItems();
    void EnemigoGenerator();

    void procesarColisiones(bool eRight, bool eLeft, bool eUp, bool eDown);
    void initAlcantarillas();



    void visionIA();
    void atacaIA();


    vector< Alcantarilla *> alcantarillas;

    void processHUD();

    void calcularPuntuacionVariable();
    void calcularTiempoBonificacion();
protected:

private:

    int ptoEntrgaActual;
    sf::RectangleShape *ptoEntrega;

    /** vista, minimap & HUD stuff **/
    Popup *warning,*pizza;

    sf::View * vista, * minimap; // La super vista y el super minimapa
    int player_lifes, num_pizzas;
    Font * font_player_lifes, *font_numbers;
    Text * text_player_lifes, *text_num_pizzas, *text_time;

    Texture * txt_pizza,*txt_hud1,*txt_hud2;
    Sprite * spr_pizza, *spr_hud1,*spr_hud2;
    Clock * clock1;
    Time * time1;
    int reparto_time;

    RectangleShape * pwupHUD_ative;
    Texture * txt_pwupHUD_empty,* txt_pwupHUD_escudo,* txt_pwupHUD_invisibilidad,
    * txt_pwupHUD_tiempo,* txt_pwupHUD_velocidad,* txt_pwupHUD_vida;

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

    sf::Clock clockAlcantarillas;

    bool entregando;
    sf::Clock clockEntrega;
    double distanciaPtoEntrega;
    int puntosPorDistancia;
    int tiempoBonificacion;
    int puntuacion;
    sf::Clock SpawnEnemigo;
    bool SpawnEnemigo_b;

};

#endif // MUNDO_H
