#ifndef JUEGO_H
#define JUEGO_H


class Juego
{
    public:
        virtual ~Juego();
        static Juego* getInstance();

    protected:
        Juego(); // constructor
        Juego(const Juego &); // operador de copia
        Juego &operator= (const Juego &); // operador de asignacion

    private:
        static Juego* jInstancia;
};

#endif // JUEGO_H
