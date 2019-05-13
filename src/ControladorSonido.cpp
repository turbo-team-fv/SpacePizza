#include "ControladorSonido.h"
#include <iostream>

ControladorSonido::ControladorSonido()
{
    //ctor

    /**CARGA CANCION MENU**/
    bufferMenu = new SoundBuffer();
    bufferMenu->loadFromFile("assets/sonidos/snarky-puppy_bad-kids-to-the-back.ogg");
    soundMenu = new Sound();
    soundMenu->setBuffer(*bufferMenu);

    /**CARGA CANCIONES RADIO**/
    buffersRadio.push_back(new SoundBuffer());
    buffersRadio[0]->loadFromFile("assets/sonidos/lettuce-chief.ogg");
    soundsRadio.push_back(new Sound());
    soundsRadio[0]->setBuffer(*buffersRadio[0]);
    soundsRadio[0]->setVolume(50.f);

    /**CARGA EFECTOŜ**/
    bufferPowerUp = new SoundBuffer();
    bufferPowerUp->loadFromFile("assets/sonidos/powerUp.ogg");
    soundPowerUp = new Sound();
    soundPowerUp->setBuffer(*bufferPowerUp);

    bufferExplosion = new SoundBuffer();
    bufferExplosion->loadFromFile("assets/sonidos/explosion.ogg");
    soundExplosion = new Sound();
    soundExplosion->setVolume(130);
    soundExplosion->setBuffer(*bufferExplosion);

    bufferTurbo = new SoundBuffer();
    bufferTurbo->loadFromFile("assets/sonidos/turboXD.ogg");
    soundTurbo = new Sound();
    soundTurbo->setVolume(130);
    soundTurbo->setBuffer(*bufferTurbo);

    bufferCesped = new SoundBuffer();
    bufferCesped->loadFromFile("assets/sonidos/cesped.ogg");
    soundCesped = new Sound();
    soundCesped->setVolume(200);
    soundCesped->setBuffer(*bufferCesped);
    soundCesped->setLoop(true);

}

ControladorSonido* ControladorSonido::instancia = new ControladorSonido();

ControladorSonido* ControladorSonido::getInstance()
{
    if(instancia == 0)
    {
        instancia = new ControladorSonido();
    }

    return instancia;
}

void ControladorSonido::playRadio(int r)
{
    if(r < soundsRadio.size())
    {
        for(unsigned i = 0; i < buffersRadio.size(); i++)
        {
            if(r != i) /// paramos todas las canciones menos la que queremos que suene
            {
                soundsRadio[i]->stop();
            }
        }

        soundsRadio[r]->play();
    }
    else
    {
        std::cout << "ERROR: Seleccion de radio fuera del rango" << std::endl;
    }
}

void ControladorSonido::playMusicaMenu()
{
    soundMenu->play();
}

void ControladorSonido::stopMusicaMenu()
{
    soundMenu->stop();
}

void ControladorSonido::playPowerUp()
{
    soundPowerUp->play();
}

void ControladorSonido::playExplosion()
{
    soundExplosion->play();
}

void ControladorSonido::playTurbo()
{
    soundTurbo->play();
}

void ControladorSonido::playCesped()
{
    soundCesped->play();
}
