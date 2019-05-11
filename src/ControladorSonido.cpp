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
