#include "ControladorSonido.h"
#include <iostream>

ControladorSonido::ControladorSonido()
{
    //ctor

    /**CARGA CANCION MENU**/
    bufferMenu = new SoundBuffer();
    bufferMenu->loadFromFile("assets/sonidos/snarky-puppy_bad-kids-to-the-back.ogg");
    soundMenu = new Sound();
    soundMenu->setVolume(50.0);
    soundMenu->setBuffer(*bufferMenu);
    soundMenu->setLoop(true);

    /**CARGA CANCIONES RADIO**/
    buffersRadio.push_back(new SoundBuffer());
    buffersRadio[0]->loadFromFile("assets/sonidos/lettuce-chief.ogg");
    soundsRadio.push_back(new Sound());
    soundsRadio[0]->setBuffer(*buffersRadio[0]);
    soundsRadio[0]->setVolume(30.f);
    soundsRadio[0]->setLoop(true);

    buffersRadio.push_back(new SoundBuffer());
    buffersRadio[1]->loadFromFile("assets/sonidos/gasolina.ogg");
    soundsRadio.push_back(new Sound());
    soundsRadio[1]->setBuffer(*buffersRadio[1]);
    soundsRadio[1]->setLoop(true);
//    soundsRadio[1]->setVolume(50.f);

    buffersRadio.push_back(new SoundBuffer());
    buffersRadio[2]->loadFromFile("assets/sonidos/lowrider.ogg");
    soundsRadio.push_back(new Sound());
    soundsRadio[2]->setBuffer(*buffersRadio[2]);
    soundsRadio[2]->setVolume(50.f);
    soundsRadio[2]->setLoop(true);

    buffersRadio.push_back(new SoundBuffer());
    buffersRadio[3]->loadFromFile("assets/sonidos/dem2.ogg");
    soundsRadio.push_back(new Sound());
    soundsRadio[3]->setBuffer(*buffersRadio[3]);
    soundsRadio[3]->setVolume(50.f);
    soundsRadio[3]->setLoop(true);

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
    soundTurbo->setVolume(250);
    soundTurbo->setBuffer(*bufferTurbo);

    bufferCesped = new SoundBuffer();
    bufferCesped->loadFromFile("assets/sonidos/cesped.ogg");
    soundCesped = new Sound();
    soundCesped->setVolume(200);
    soundCesped->setBuffer(*bufferCesped);
    soundCesped->setLoop(true);

    bufferDerrape = new SoundBuffer();
    bufferDerrape->loadFromFile("assets/sonidos/derrape.ogg");
    soundDerrape = new Sound();
    soundDerrape->setVolume(200);
    soundDerrape->setBuffer(*bufferDerrape);
    soundDerrape->setLoop(false);


    bufferFin = new SoundBuffer();
    bufferFin->loadFromFile("assets/sonidos/homeboy-sandman-edan-the-gut.ogg");
    soundFin = new Sound();
    soundFin->setVolume(200);
    soundFin->setBuffer(*bufferFin);
    soundFin->setLoop(false);

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
        radioActiva = r;
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
void ControladorSonido::stopFin()
{
    soundFin->stop();
}
void ControladorSonido::playFin()
{
    soundFin->play();
}

void ControladorSonido::stopMusica()
{
    soundMenu->stop();
    soundCesped->stop();
    reproduciendoCesped = false;
    soundDerrape->stop();
    reproduciendoDerrape = false;
    stopRadio();
}
void ControladorSonido::stopAlien()
{

}
void ControladorSonido::stopRadio()
{
    for(unsigned i=0; i<soundsRadio.size(); i++){
    soundsRadio[i]->stop();
    }
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
    if(reproduciendoCesped == false)
    {
        soundCesped->play();
        reproduciendoCesped = true;
    }
}

void ControladorSonido::stopCesped()
{
    soundCesped->stop();
    reproduciendoCesped = false;
}

void ControladorSonido::playDerrape()
{
    if(reproduciendoDerrape == false)
    {
        soundDerrape->play();
        reproduciendoDerrape = true;
    }
}

void ControladorSonido::stopDerrape()
{
    soundDerrape->stop();
    reproduciendoDerrape = false;
}
