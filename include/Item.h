#ifndef ITEM_H
#define ITEM_H
#include <SFML/Graphics.hpp>"

class Item
{
    public:
        Item(int tipo, sf::Vector2f pos, int tiempoG, int tiempoV);
        virtual ~Item();
        int getTipo();
        int getTiempoGeneracion();
        int getTiempoVida();
        sf::Clock getClock();
        sf::Sprite getSprite();
        sf::Vector2f getPosicion();
        void restartPowerUp();

    protected:

    private:
        int tipo;
        int tiempoGeneracion;
        int tiempoVida;
        sf::Clock reloj;
        sf::Vector2f posicion;
        sf::Sprite *sprite;
        sf::Texture textura;


};

#endif // ITEM_H
