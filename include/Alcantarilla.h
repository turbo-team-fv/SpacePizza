#ifndef ALCANTARILLA_H
#define ALCANTARILLA_H
#include <SFML/Graphics.hpp>"


class Alcantarilla
{
    public:
        Alcantarilla(sf::Vector2f posI, sf::Vector2f posF);
        virtual ~Alcantarilla();
        sf::Vector2f getPosInicial();
        sf::Vector2f getPosDestino();
        sf::CircleShape getForma();
        void drawAlcantarilla(sf::RenderWindow *window);

    protected:

    private:
        sf::Vector2f posInicial;
        sf::Vector2f posDestino;
        sf::CircleShape *forma;
};

#endif // ALCANTARILLA_H
