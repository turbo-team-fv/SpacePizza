#include "SuperSprite.h"

SuperSprite::SuperSprite(string ruta, int numanim, double escala, bool isanimado)
{
    //ctor
    s_sprite=new sf::Sprite();
    textura =new sf::Texture();

    frames.resize(numanim);

    textura->loadFromFile(ruta);
    if (!textura->loadFromFile(ruta))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }

    speed=0.2;
    s_sprite->setTexture(*textura);
    s_sprite->scale(escala,escala);

    animacion=0;
    frame=0;
    animado=isanimado;
    renderPos.x=0;renderPos.y=0;

}

void SuperSprite::addFrame(sf::IntRect frame,int animation)
{
    if(animation<frames.size())
    {
        frames[animation].push_back(frame);
    }
}

void SuperSprite::setSpeed(double s)
{
    speed=s;
}

void SuperSprite::setAnimation(int a)
{
    animacion=a;
}

sf::Sprite* SuperSprite::getActualSprite()
{
    return s_sprite;
}
sf::Vector2f SuperSprite::getRenderPos(){

    return renderPos;
}
void SuperSprite::calcInter(sf::Vector2f past, sf::Vector2f actual,sf::RenderWindow *w, double i){


/** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    renderPos=(actual-past)*(float)i+past;
    //renderPos.y=(actual.y-past.y)*i+past.y;

}
void SuperSprite::drawSuperSprite(sf::Vector2f  past, sf::Vector2f actual,sf::RenderWindow *w, double i)
{

    if(changer.getElapsedTime().asSeconds()>speed&&animado)
    {
        if(animacion<frames.size())
        {
            frame++;
            if(frame==frames[animacion].size()){
            frame=0;

            }
        }
    changer.restart();
    }
    s_sprite->setOrigin(frames[animacion][frame].width/2,frames[animacion][frame].height/2);
    s_sprite->setTextureRect(frames[animacion][frame]);


    calcInter(past,actual,w,i);

    s_sprite->setPosition(renderPos.x, renderPos.y);
    w->draw(*s_sprite);

}

SuperSprite::~SuperSprite()
{
    //dtor
}
