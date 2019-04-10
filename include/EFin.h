#ifndef EFIN_H
#define EFIN_H


class EFin
{
    public:
        EFin * getInstance();

    private:
        static EFin * eFinInstancia;
        EFin();

};

#endif // EFIN_H
