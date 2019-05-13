#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "PhysicsState.h"
#include "SuperSprite.h"
#include "Popup.h"

class Enemigo
{
    public:
        Enemigo();
        virtual ~Enemigo();
        PhysicsState* getPhysicsState();
        void updateEnemigo(sf::Vector2f vel, sf::Time et);

        void calcInter(sf::RenderWindow *w, double i);
        void drawEnemigo(sf::RenderWindow *w, double i);
        SuperSprite* getSprite(){ return enemigo_sprite; };

        void setVision(bool v);
        void setAtaque(bool v);
        void setActitud(int a);
        void setVolumen(float v);

        bool getVision(){return teveo;};
        bool getAtaque(){return teataco;};
        int getActitud(){return actitud;};

    protected:

    private:
    /**GRAFICOS**/
    SuperSprite *enemigo_sprite;
    vector <Popup*> alert;
    int alert_id;
    /**SONIDO**/
    sf::SoundBuffer *bufferAlien;
    sf::Sound *soundAlien;


    /**FISICAS**/
    PhysicsState *pState;

    /**OTROS**/
    int actitud; //0: Apatrullando la ciudad, 1: En alerta, 2: Te persigue
    double tiempo_espera; // sera un random de espera entre movimiento y movimiento
    double tiempo_alerta;
    double tiempo_persecucion;
    double tiempo_ataque;

    sf::Clock movingclock;
    sf::Clock alertclock;
    sf::Clock chaseclock;
    sf::Clock atackClock;

    bool teveo; //Controla si esta viendo al jugador o no
    bool teataco;

    int direccion_patrullaje; // 0: quieto, 1: izquierda, 2: derecha, 3: arriba, 4: abajo
    int direccion_patrullaje2; // 0: quieto, 1: izquierda, 2: derecha, 3: arriba, 4: abajo

};

#endif // ENEMIGO_H
