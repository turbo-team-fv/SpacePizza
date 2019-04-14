#ifndef MAQUINAESTADOS_H
#define MAQUINAESTADOS_H

#include <vector>
#include "State.h"

class MaquinaEstados
{
    public:
        MaquinaEstados();
        virtual ~MaquinaEstados();

        /**MANEJO DE ESTADOS**/
        void AddState(State * state);


    private:
        std::vector<State*> estados;

};

#endif // MAQUINAESTADOS_H
