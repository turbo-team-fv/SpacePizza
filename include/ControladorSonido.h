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
        void playPowerUp();

    private:
        ControladorSonido();
        static ControladorSonido *instancia;

        SoundBuffer *bufferMenu;
        Sound *soundMenu;

        std::vector<SoundBuffer*> buffersRadio;
        std::vector<Sound*> soundsRadio;

        SoundBuffer *bufferPowerUp;
        Sound *soundPowerUp;

};

#endif // CONTROLADORSONIDO_H
