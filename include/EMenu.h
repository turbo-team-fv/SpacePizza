#ifndef EMENU_H
#define EMENU_H
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "State.h"

using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

class EMenu : public State
{
    public:
        static EMenu* getInstance();
        void draw(RenderWindow * window);
        void MoveUp();
        void MoveDown();
        int getSelectedItem();

        void Init();
        void HandleInput();
        void Update();
        void Draw(float);

    private:
        EMenu();
        static EMenu * eMenuInstancia;
        int selectedItemIndex;
        Font font;
        Sprite * bg_menu;
        Texture * bgMenu_txt;
        Text menu[MAX_NUMBER_OF_ITEMS];

};

#endif // EMENU_H
