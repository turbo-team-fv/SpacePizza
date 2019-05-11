#ifndef CONTROLADORSONIDO_H
#define CONTROLADORSONIDO_H

#include <vector>
#include "SFML/Audio.hpp"

using namespace sf;

class ControladorSonido
{
    public:
        static ControladorSonido* getInstance();
        void playRadio(int r);
        void playMusicaMenu();
        void stopMusicaMenu();

    private:
        ControladorSonido();
        static ControladorSonido *instancia;

        SoundBuffer *bufferMenu;
        Sound *soundMenu;

        std::vector<SoundBuffer*> buffersRadio;
        std::vector<Sound*> soundsRadio;


};

#endif // CONTROLADORSONIDO_H
