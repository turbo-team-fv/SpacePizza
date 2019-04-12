#ifndef EMENU_H
#define EMENU_H
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

class EMenu
{
    public:
        static EMenu* getInstance();
        void draw(RenderWindow * window);
        void MoveUp();
        void MoveDown();
        int getSelectedItem();

    private:
        EMenu();
        static EMenu * eMenuInstancia;
        int selectedItemIndex;
        Font font;
        Text menu[MAX_NUMBER_OF_ITEMS];

};

#endif // EMENU_H
