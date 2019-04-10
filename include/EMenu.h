#ifndef EMENU_H
#define EMENU_H


class EMenu
{
    public:
        static EMenu* getInstance();

    private:
        EMenu();
        static EMenu * eMenuInstancia;
};

#endif // EMENU_H
