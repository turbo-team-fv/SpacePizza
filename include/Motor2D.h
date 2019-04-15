#ifndef MOTOR2D_H
#define MOTOR2D_H

#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Motor2D{
    public:
        static Motor2D* Instance();
        RenderWindow * getWindow();
        void dibujar(Sprite);
        void clearWindow();
        bool openWindow();
        void displayWindow();
        void closeWindow();
        void setCamera();
        void resetCamera();
        void setFrameLimit();

    private:
        Motor2D();
        Motor2D(const Motor2D&);
        Motor2D &operator= (const Motor2D &);
        static Motor2D* pinstance;
        RenderWindow window;
};

#endif
