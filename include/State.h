#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class State
{
    public:
        virtual void Init() = 0;
        virtual void HandleEvents(RenderWindow * ventana) = 0;
        virtual void Update() = 0;
        virtual void loop(RenderWindow * ventana, Time timePerFrame) = 0;
        virtual void Draw(RenderWindow * ventana) = 0;

    private:
};

#endif // STATE_H
