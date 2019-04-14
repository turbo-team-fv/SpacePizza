#ifndef EFIN_H
#define EFIN_H
#include "State.h"

class EFin : public State
{
    public:
        EFin * getInstance();

    private:
        static EFin * eFinInstancia;
        EFin();

};

#endif // EFIN_H
