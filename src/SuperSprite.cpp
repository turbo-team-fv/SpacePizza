#include "SuperSprite.h"

SuperSprite::SuperSprite(string ruta, int numanim, double escala, bool isanimado)
{
    //ctor
    s_sprite=new sf::Sprite();
    textura =new sf::Texture();
    //La carga de texturas podria ser otra clase
    frames.resize(numanim);
    /*for (int i = 0 ; i < 4 ; i++)
    	frames[i].resize(2);*/

    textura->loadFromFile("assets/jugador/sp_alien_texture.png");
    if (!textura->loadFromFile("assets/jugador/sp_alien_texture.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }

    speed=0.2;
    s_sprite->setTexture(*textura);
    s_sprite->scale(0.6,0.6);

    animacion=0;
    frame=0;
    animado=isanimado;
    renderPos.push_back(0.0);
    renderPos.push_back(0.0);

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
vector<double> SuperSprite::getRenderPos(){

    return renderPos;
}
void SuperSprite::calcInter(vector<double> past, vector<double> actual,sf::RenderWindow *w, double i){


/** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    renderPos[0]=(actual[0]-past[0])*i+past[0];
    renderPos[1]=(actual[1]-past[1])*i+past[1];

}
void SuperSprite::drawSuperSprite(vector<double> past, vector<double> actual,sf::RenderWindow *w, double i)
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

    s_sprite->setPosition(renderPos[0], renderPos[1]);
    w->draw(*s_sprite);

}

SuperSprite::~SuperSprite()
{
    //dtor
}
