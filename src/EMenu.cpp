#include "EMenu.h"

EMenu::EMenu()
{
    //ctor
}

EMenu* EMenu::eMenuInstancia = 0;

EMenu* EMenu::getInstance()
{
    if(eMenuInstancia==0)
    {
        eMenuInstancia = new EMenu();
    }

    return eMenuInstancia;
}
