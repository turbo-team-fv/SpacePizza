#ifndef ECOMO_H
#define ECOMO_h
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "ControladorSonido.h"

using namespace std;
using namespace sf;

class EComo : public State
{
    public:
        static EComo* getInstance();

        void HandleInputs(sf::Keyboard::Key key, bool isPressed);
        int getSelectedItem();
        void MoveRight();
        void MoveLeft();

        /**STATE**/
        void Init();
        void HandleEvents(RenderWindow * ventana);
        void loop(RenderWindow * ventana, Time timePerFrame);
        void Update();
        void Draw(RenderWindow * ventana);

    private:
        EComo();
        static EComo * EComoInstancia;

        Font font;

        Texture * primera;
        Texture * segunda;
        Texture * tercera;
        Texture * cuarta;
        Texture * quinta;
        Texture * sexta;

        Sprite *bg[6];

        Text menu[2];

        int numero=-1;
        int contador;
        bool cambiar=false;

        int selectedItemIndex;
};

#endif // ECOMO_H
