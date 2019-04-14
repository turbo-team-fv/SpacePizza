#ifndef EFIN_H
#define EFIN_H
#include "State.h"

class EFin : public State
{
public:
    static EFin * getInstance();
    void Init();
    void HandleInput(RenderWindow * ventana);
    void Update();
    void Draw(RenderWindow * ventana);

protected:
    EFin(); // constructor
    EFin(const EFin &); // operador de copia
    EFin &operator= (const EFin &); // operador de asignacion
private:
    static EFin * eFinInstancia;

};

#endif // EFIN_H
