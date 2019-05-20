#ifndef EFIN_H
#define EFIN_H
#include "State.h"
#include "SuperSprite.h"
#include "ControladorSonido.h"
#include "SFML/Graphics.hpp"


using namespace std;
using namespace sf;

class EFin : public State
{
    public:
        static EFin* getInstance();

        void HandleInputs(sf::Keyboard::Key key, bool isPressed);
        int getSelectedItem();
        void MoveRight();
        void MoveLeft();

        /**STATE**/
        void Init();
        void restartRank();
        void HandleEvents(RenderWindow * ventana);
        void loop(RenderWindow * ventana, Time timePerFrame);
        void Update();
        void Draw(RenderWindow * ventana);

    private:
        EFin();
        static EFin * EFinInstancia;

        Font font;

        Texture * primera;
        Texture * segunda;
        Texture * tercera;
        Texture * cuarta;
        Texture * quinta;
        Texture * sexta;

        Sprite *bg[6];

        Text menu[2];
        Text puntuacion,estilo,pizzas;

        Clock dibujado;

        int numero=-1;
        int contador;
        bool cambiar=false,dibuja=false;
        int in_puntos,out_puntos,in_pizzas,out_pizzas,in_estilo,out_estilo;
        string s_puntos,s_pizzas,s_estilo;

        int selectedItemIndex;
};


#endif // EFIN_H
