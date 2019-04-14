#ifndef STATE_H
#define STATE_H


class State
{
    public:
        virtual void Init() = 0;
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        virtual void Draw(float) = 0;

    private:
};

#endif // STATE_H
