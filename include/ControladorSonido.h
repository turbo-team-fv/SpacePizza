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
        void playAlien();

        void playExplosion();
        void playTurbo();
        void playCesped();
        void playDerrape();
        void stopCesped();
        void stopDerrape();
        void stopMusica();
        void stopAlien();
        void stopRadio();
        void stopFin();
        void playFin();

        int getRadioActiva() { return radioActiva; }

    private:
        ControladorSonido();
        static ControladorSonido *instancia;

        int radioActiva = 0;

        SoundBuffer *bufferMenu;
        Sound *soundMenu;

        std::vector<SoundBuffer*> buffersRadio;
        std::vector<Sound*> soundsRadio;

        SoundBuffer *bufferPowerUp;
        Sound *soundPowerUp;

        SoundBuffer *bufferExplosion;
        Sound *soundExplosion;

        SoundBuffer *bufferTurbo;
        Sound *soundTurbo;

        SoundBuffer *bufferFin;
        Sound *soundFin;

        SoundBuffer *bufferAddPoint;
        Sound *addPoint;

        bool reproduciendoCesped = false;
        SoundBuffer *bufferCesped;
        Sound *soundCesped;

        bool reproduciendoDerrape = false;
        SoundBuffer *bufferDerrape;
        Sound *soundDerrape;

};

#endif // CONTROLADORSONIDO_H
