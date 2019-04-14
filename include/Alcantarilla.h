#ifndef ALCANTARILLA_H
#define ALCANTARILLA_H
#include <SFML/Graphics.hpp>"


class Alcantarilla
{
    public:
        Alcantarilla(sf::Vector2f posI);
        virtual ~Alcantarilla();
        sf::Vector2f getPosInicial();
        sf::CircleShape getForma();
        void drawAlcantarilla(sf::RenderWindow *window);

    protected:

    private:
        sf::Vector2f posInicial;
        sf::CircleShape *forma;
        sf::Texture texture;
        sf::Sprite *sprite;
};

#endif // ALCANTARILLA_H
