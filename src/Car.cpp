#include "Car.h"
#include "Path.h"
#include "MathHelper.h"
#include <iostream>

Car::Car(unsigned int l_type, const sf::Vector2f& l_position, Path * l_path)
{
    type  = l_type;
    path  = l_path;

    Init();

    sprite->setPosition(l_position);
}

Car::~Car()
{
    delete sprite;
    delete texture;
}

//Inicializa el coche teniendo en cuenta el tipo de coche.
void Car::Init()
{
    if(type == light)
    {
        //Green car.
        frames["right"] = sf::IntRect(583,280,38,25);
        frames["left"] = sf::IntRect(534,280,38,25);
        frames["up"] = sf::IntRect(532,308,23,30);
        frames["down"] = sf::IntRect(532,308,23,30);
        InitSprite(frames["down"]);
        maxVelocity = 100.0f;
    }
    else if(type == normal)
    {
        //Blue car.
        frames["right"] = sf::IntRect(583,348,38,25);
        frames["left"] = sf::IntRect(534,348,38,25);
        frames["up"] = sf::IntRect(532,376,23,30);
        frames["down"] = sf::IntRect(566,376,23,30);
        InitSprite(frames["down"]);
        maxVelocity = 80.0f;
    }
    else
    {
        //Red car.
        frames["right"] = sf::IntRect(583,416,38,25);
        frames["left"] = sf::IntRect(534,416,38,25);
        frames["up"] = sf::IntRect(532,444,23,30);
        frames["down"] = sf::IntRect(566,444,23,30);
        InitSprite(frames["down"]);
        maxVelocity = 50.0f;
    }

    currentWP = 0;
    currentTarget = path->waypoints[0];
}

//Inicializa el sprite del coche.
void Car::InitSprite(const sf::IntRect& l_rect)
{
    sprite = new sf::Sprite();
    texture = new sf::Texture();

    if (!texture->loadFromFile("assets/maps/roguelikeCity_magenta3.png"))
    {
        std::cout<< "Error cargando la imagen roguelikeCity_magenta3.png"<<std::endl;
        exit(0);
    }

    sprite->setTexture(*texture);
    sprite->setTextureRect(l_rect);
    sprite->setOrigin(sprite->getGlobalBounds().width / 2, sprite->getGlobalBounds().height / 2);
    sprite->setScale(1,1);
}

//Actualiza el Path following del coche.
void Car::Update(sf::Time elapsedTime)
{
    PathFollowing(elapsedTime);
}

//Funcion de movimiento del coche a lo largo de un path.
void Car::PathFollowing(sf::Time elapsedTime)
{
    //Calculo la distancia desde mi posicion al proximo waypoint.
    float dist = Distance(currentTarget, sprite->getPosition());
    //Si la distancia es menos al radio del waypoint
    if(dist <= path->pathRadius)
    {
        //Apunto al siguiente.
        currentWP++;
        //Si el waypoint al que apunto no existe
        if(currentWP >= path->pathSize)
        {
            //Apunto al primero.
            currentWP = 0;
        }
    }
    //Almaceno el waypoint al que apunto.
    currentTarget = path->waypoints[currentWP];
    //Mueve el sprite del coche.
    Seek(currentTarget, elapsedTime);
}

//Steering behavior.
void Car::Seek(sf::Vector2f l_target, sf::Time elapsedTime)
{
    //Direccion en la que debe moverse el coche (normalizada).
    sf::Vector2f nDir = NormalizedDirection(l_target, sprite->getPosition());
    //Chequeo el cambio de direccion de sprite.
    CheckSpriteDirection(nDir);
    //Para optimizar multiplicaciones, la hago solo una vez.
    float ve = maxVelocity * elapsedTime.asSeconds();

    lastPos=actualPos;

    actualPos.x+=nDir.x * ve;
    actualPos.y+=nDir.y * ve;
    //Movemos el sprite del coche a su velocidad maxima.
    //sprite->move(sf::Vector2f(nDir.x * ve, nDir.y * ve));
}

//Chequeo que sprite tiene que cambiar.
void Car::CheckSpriteDirection(const sf::Vector2f& l_dir)
{
    float x = l_dir.x;
    float y = l_dir.y;

    //std::cout << "dir:" << l_dir.x << ", " << l_dir.y << std::endl;

        if(x >= 0.5 && y < 0.2)
        {
            sprite->setTextureRect(frames["right"]);
            sprite->setOrigin(sprite->getGlobalBounds().width / 2, sprite->getGlobalBounds().height / 2);
        }
        else if(x < -0.5 && y < 0.2)
        {
            sprite->setTextureRect(frames["left"]);
            sprite->setOrigin(sprite->getGlobalBounds().width / 2, sprite->getGlobalBounds().height / 2);
        }
        else if(y >= 0.5 && x < 0.2)
        {
            sprite->setTextureRect(frames["down"]);
            sprite->setOrigin(sprite->getGlobalBounds().width / 2, sprite->getGlobalBounds().height / 2);
        }
        else if(y < -0.5 && x < 0.2)
        {
            sprite->setTextureRect(frames["up"]);
            sprite->setOrigin(sprite->getGlobalBounds().width / 2, sprite->getGlobalBounds().height / 2);
        }

}

//Dibujado del coche.
void Car::Draw(sf::RenderWindow *w, double i)
{
     /** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    /** Posicion = (Estado_actual - Estado_pasado) * Interpolacion + Estado_pasado **/
    renderPos=(actualPos-lastPos)*(float)i+lastPos;

    sprite->setPosition(renderPos.x,renderPos.y);
    w->draw(*sprite);
}
