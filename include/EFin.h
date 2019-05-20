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

        int numero=-1;
        int contador;
        bool cambiar=false;

        int selectedItemIndex;
};


#endif // EFIN_H
