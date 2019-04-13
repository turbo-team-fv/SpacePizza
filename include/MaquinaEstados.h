#ifndef MAQUINAESTADOS_H
#define MAQUINAESTADOS_H

#include "EMenu.h"
#include "EJugando.h"
#include "EFin.h"

class MaquinaEstados
{
    public:
        MaquinaEstados();
        virtual ~MaquinaEstados();
        void sacarMenu();
        void comenzarJuego();
        void finalizarJuego();

    private:
        EMenu * eMenu;
        EJugando * eJugando;
        EFin * eFin;

};

#endif // MAQUINAESTADOS_H
