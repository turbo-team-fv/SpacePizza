#ifndef EJUGANDO_H
#define EJUGANDO_H


class EJugando
{
    public:
        EJugando * getInstance();

    private:
        EJugando();
        static EJugando * eJugandoInstancia;
};

#endif // EJUGANDO_H
