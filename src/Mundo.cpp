#include "Mundo.h"
#include "Juego.h"

Mundo::Mundo()
{
    //ctor
    ptoEntrgaActual = 0;
    pizzas = 0;

    // Inicializo los puntos de entrega
    initPuntosEntrega();
    //inicializo los items
    initItems();


    /**EELEMENTOS**/
    mapa = new Mapa();
    p1 = new Jugador();

    e1.resize(4);

    for(unsigned en=0; en < e1.size(); en++)
    {
        e1 [en]= new Enemigo();
    }



    /** HUD, vista and minimap stuff **/
    // HUD
    // 4th dimension
    clock1 = new Clock();
    time1 = new Time();
    reparto_time = 30;
    player_lifes = p1->getVidas();
    num_pizzas = 0;
    txt_pizza = new Texture();
    txt_pizza -> loadFromFile("assets/hud/pizza.png");
    spr_pizza = new Sprite(*txt_pizza);
    spr_pizza -> setScale(20.f/338, 20.f/400);

    font_numbers = new Font();
    font_numbers ->loadFromFile("assets/hud/fullPack2025.ttf");
    font_player_lifes = new Font();
    font_player_lifes ->loadFromFile("assets/hud/HeartsSt.ttf");
    text_num_pizzas = new Text();
    text_num_pizzas -> setFont(*font_numbers);
    text_num_pizzas -> setCharacterSize(15);
    text_time = new Text();
    text_time -> setFont(*font_numbers);
    text_time -> setCharacterSize(15);
    text_player_lifes = new Text();
    text_player_lifes -> setFont(*font_player_lifes);
    text_player_lifes -> setCharacterSize(15);
    text_player_lifes -> setColor(Color::Red);

    // Vista
    vista = new View();
    vista -> reset(sf::FloatRect(p1->getPhysicsState()->getActualState()[0],p1->getPhysicsState()->getActualState()[1], 300, 200));
    vista->setCenter((float)p1->getPhysicsState()->getActualState()[0], (float)p1->getPhysicsState()->getActualState()[1]);
    vista->setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    // Minimap
    minimap = new View();
    minimap->setViewport(sf::FloatRect(0.75f, 0.75f, 0.25f, 0.25f));

    tiempo = 10;

    initAlcantarillas();
}

int Mundo::getPtoEntregaActual()
{
    return ptoEntrgaActual;
}

std::vector<Item*> Mundo::getItems()
{
    return items;
}

std::vector<sf::Vector2f> Mundo::getPuntosEntrega()
{
    return puntosEntrega;
}

void Mundo::atacaIA()
{
    int rango=20;

    for(unsigned en=0; en< e1.size(); en++)
    {
        if((abs(p1->getSprite()->getRenderPos()[0]-e1[en]->getSprite()->getRenderPos()[0])<rango)
                &&(abs(p1->getSprite()->getRenderPos()[1]-e1[en]->getSprite()->getRenderPos()[1])<rango))
        {
            if(e1[en]->getAtaque())
            {
                cout<<"ATAQUE HIJO PUTA"<<endl;
                p1->updateVida(-1);

            }
        }
    }
}

void Mundo::visionIA()
{
    int rango=100;
    if(p1->checkEstado()!=2)
    {
        for(unsigned en=0; en< e1.size(); en++)
        {
            if((abs(p1->getSprite()->getRenderPos()[0]-e1[en]->getSprite()->getRenderPos()[0])<rango)
                    &&(abs(p1->getSprite()->getRenderPos()[1]-e1[en]->getSprite()->getRenderPos()[1])<rango))
            {
                e1[en]->setVision(true);
            }
            else
            {
                e1[en]->setVision(false);
            }
        }

    }
    else
    {
        cout<<"MODO INVISIBLE"<<endl;
    }
}


void Mundo::colisionesMapa()
{

    float offset=0;
    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[0])!=0)
    {
        p1->getPhysicsState()->Move(0,-150,true);
        //p1->getPhysicsState()->MoveTo(p1->getPhysicsState()->getActualState()[0],p1->getPhysicsState()->getActualState()[1]-20);
    }

    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[1])!=0)
    {

        p1->getPhysicsState()->Move(+150,0,true);
//        eLeft = false;
    }

    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[2])!=0)
    {

        p1->getPhysicsState()->Move(-150,0,true);
        // eRight = false;
    }

    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[3])!=0)
    {

        p1->getPhysicsState()->Move(0,+150,true);
        //  eUp = false;
    }


}

void Mundo::colisionAlcantarilla(bool eRight, bool eLeft, bool eUp, bool eDown)
{

/// Colisiones con las alcantarillas
    for( int i = 0; i < alcantarillas.size(); i++ )
    {
        if(p1->getSprite()->getActualSprite()->getGlobalBounds().intersects(alcantarillas[i]->getSprite().getGlobalBounds()))
        {
            //p1->getPhysicsState()->MoveTo((double) 500, (double) 425);
            // p1->getPhysicsState()->MovePlayerTo((double) 500, (double) 425);

            /**Comprobamos destino**/
            if(i == alcantarillas.size() -1)
            {
                if(eRight)
                {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[0]->getPosInicial().x+30, (double)alcantarillas[0]->getPosInicial().y);
                }
                else if(eLeft)
                {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[0]->getPosInicial().x-30, (double)alcantarillas[0]->getPosInicial().y);
                }
                else if(eDown)
                {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[0]->getPosInicial().x, (double)alcantarillas[0]->getPosInicial().y+30);
                }
                else if(eUp)
                {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[0]->getPosInicial().x, (double)alcantarillas[0]->getPosInicial().y-30);
                }

            }
            else
            {
                if(eRight)
                {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[i+1]->getPosInicial().x+30, (double)alcantarillas[i+1]->getPosInicial().y);
                }
                else if(eLeft)
                {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[i+1]->getPosInicial().x-30, (double)alcantarillas[i+1]->getPosInicial().y);
                }
                else if(eDown)
                {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[i+1]->getPosInicial().x, (double)alcantarillas[i+1]->getPosInicial().y+30);
                }
                else if(eUp)
                {
                    p1->getPhysicsState()->MoveTo((double)alcantarillas[i+1]->getPosInicial().x, (double)alcantarillas[i+1]->getPosInicial().y-30);
                }
            }
            std::cout<<"Destino Alcanzado x: "<<p1->getPhysicsState()->getActualState()[0]<<std::endl;
        }
    }

}
void Mundo::colisionItems()
{

/// Colisones con los PowerUps
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i]->getSprite().getGlobalBounds().intersects(p1->getSprite()->getActualSprite()->getGlobalBounds()) && items[i]->isActivo())
        {
            // Colision del jugador con uno de los powerUps del vector
            std::cout<<"Colision con un item"<<std::endl;
            int tipo = items[i]->getTipo();
            std::cout<<tipo<<std::endl;
            switch (tipo)
            {
            case 1:
                //Colisiona con una vida
                items[i]->restartPowerUp();
                p1->updateVida(1);
                break;
            case 2:
                // Colisiona con un turbo => aumenta la velocidad durante un perido de tiempo
                items[i]->restartPowerUp();
                p1->setEstado(1);
                p1->restartEstado();
                break;
            case 3:
                // Colisiona con un tiempo
                // juego->tiempo += 10
                //Juego.getInstance()->updateTime(10);
                tiempo += 10;
                reparto_time +=10;
                items[i]->restartPowerUp();
                break;
            case 4:
                // Colisiona con una invisibilidad => cambiar la IA del Enemigo?
                items[i]->restartPowerUp();
                p1->setEstado(2);
                p1->restartEstado();
                break;
            }
            case 5:
                // Colisiona con uno de tipo Levitar => Quitar colisiones edificios
                std::cout<<"Colision con un powerUp de tipo Levitar"<<std::endl;
                items[i]->restartPowerUp();
            break;
            case 6:
                // Colisiona con modo imparable => ¿?
                std::cout<<"Colisiona con un powerUp de tip Imparable"<<std::endl;
                items[i]->restartPowerUp();
            break;
        }
    }

}
void Mundo::procesarColisiones(bool eRight, bool eLeft, bool eUp, bool eDown)
{
    visionIA();
    atacaIA();
    colisionesMapa();
    colisionItems();
    /// Colisiones con los puntos de entrega
    if(puntoEntrega->getGlobalBounds().intersects(p1->getSprite()->getActualSprite()->getGlobalBounds()))
    {
        //jugador.puntuacion + 10;
        if(ptoEntrgaActual == puntosEntrega.size() - 1)
        {
            ptoEntrgaActual = 0;
        }
        else
        {
            ptoEntrgaActual++;
            reparto_time +=10;
        }
        puntoEntrega->setPosition(puntosEntrega[ptoEntrgaActual]);
        pizzas++;
    }
    // colisionAlcantarilla(eRight,eLeft, eUp, eDown);
    colisionAlcantarilla(eRight,eLeft, eUp, eDown);


}

void Mundo::updateMundo(bool eRight, bool eLeft, bool eUp, bool eDown, sf::Time t)
{
    procesarColisiones(eRight,eLeft,eUp,eDown);
    p1->updateJugador(eRight,eLeft,eUp,eDown,t);
    for(unsigned en=0; en< e1.size(); en++)
    {

        e1[en]->updateEnemigo(p1->getPhysicsState()->getActualState()[0],p1->getPhysicsState()->getActualState()[1],t);

    }

    processHUD();


}

/**Metodo para processar los elementos del HUD*/
void Mundo::processHUD()
{
    player_lifes = p1->getVidas();
    // hay que hacer lo de las vidas y tal cogerlas de p1
    // Primero vamos acolocar los elementos sabrosos
    *time1 = clock1->getElapsedTime();

    std::stringstream ss;  // #include <sstream>
    ss << setw(2) << setfill('0') << ptoEntrgaActual;
    std::stringstream ss1;
    if((reparto_time - (int)time1->asSeconds()) > 60){
      ss1 << setw(2) << setfill('0') << (reparto_time - (int)time1->asSeconds()) - 60;
    }else{
     ss1 << setw(2) << setfill('0') << (reparto_time - (int)time1->asSeconds());

    }

    std::stringstream ss2;
    ss2 << setw(2) << setfill('0') << (int)((reparto_time - (int)time1->asSeconds())/60);
    /*t_score.setString("score  "+ss.str()+"");
    t_score.setCharacterSize(23);
    t_score.setColor(sf::Color::White);
    t_score.setStyle(sf::Text::Bold);
    t_score.setOrigin(0,0);
    t_score.setPosition(16.0,-8.0);*/

    text_num_pizzas -> setString(ss.str());
    text_time -> setString(ss2.str()+":"+ss1.str());

    string strAux;
    for (int i = 0; i<player_lifes; i++ )
    {
        strAux.append("b");
    }
    text_player_lifes -> setString(strAux);

    // Se que esto no va aqui pero ya lo pondremos mejor
    if(player_lifes == 0 || (reparto_time - (int)time1->asSeconds()) == 0){
        exit(0);
    }
}


void Mundo::drawItems(sf::RenderWindow * ventana)
{

    // Dibujo los powerUps
    for( int i = 0; i < items.size(); i++ )
    {
        float duracion = items[i]->getClock().getElapsedTime().asSeconds();
        if(duracion > items[i]->getTiempoGeneracion() && duracion < items[i]->getTiempoVida() + items[i]->getTiempoGeneracion())
        {
            items[i]->drawItem(ventana);
        }
        if(duracion > items[i]->getTiempoVida() + items[i]->getTiempoGeneracion())
        {
            items[i]->restartPowerUp();
        }
    }
}



void Mundo::drawMundo(sf::RenderWindow * ventana, double inter)
{
    /***PRIMERO RECALCULAMOS POSICION DE OBJETOS INTERPOLADOS***/
    /**Por algun motivo que no acabo de comprender**/
    p1->calcInter(ventana,inter);
    for(unsigned en=0; en< e1.size(); en++)
    {

        //e1[en]->calcInter(ventana,inter);
    }


    vista->setCenter(p1->getSprite()->getRenderPos()[0],p1->getSprite()->getRenderPos()[1]);///SET CAMERA PLAYER
    ventana->setView(*vista);///SET VIEW PLAYER
    mapa->draw(ventana);
    ventana->draw(*puntoEntrega);
    drawItems(ventana);
    drawAlcantarillas(ventana);

    p1->drawJugador(ventana,inter);
    p1->getPhysicsState()->drawColliders(ventana,inter);
    for(unsigned en=0; en< e1.size(); en++)
    {
       // e1[en]->drawEnemigo(ventana,inter);
    }

    /// HUD STUFF
    spr_pizza ->setPosition(p1->getSprite()->getRenderPos()[0],p1->getSprite()->getRenderPos()[1] - 100);
    ventana->draw(*spr_pizza);
    text_num_pizzas -> setPosition(p1->getSprite()->getRenderPos()[0]+20,p1->getSprite()->getRenderPos()[1] - 100);
    ventana->draw(*text_num_pizzas);
    text_time -> setPosition(p1->getSprite()->getRenderPos()[0]+70,p1->getSprite()->getRenderPos()[1] - 100);
    ventana->draw(*text_time);
    text_player_lifes -> setPosition(p1->getSprite()->getRenderPos()[0]-140,p1->getSprite()->getRenderPos()[1] - 100);
    ventana->draw(*text_player_lifes);


    ventana->setView(*minimap);///SET VIEW MAP
    mapa->draw(ventana);
    ventana->draw(*puntoEntrega);
    drawItems(ventana);
    p1->drawJugador(ventana,inter);


    for(unsigned en=0; en< e1.size(); en++)
    {

       // e1[en]->drawEnemigo(ventana,inter);
    }




}

void Mundo::drawAlcantarillas(sf::RenderWindow * ventana)
{


    for(int i = 0; i < alcantarillas.size(); i++ )
    {
        alcantarillas[i]->drawAlcantarilla(ventana);
    }

}
/// Metodo para inizializar las Alcantarillas del Mundo
void Mundo::initAlcantarillas()
{
    Alcantarilla *alc1 = new Alcantarilla(sf::Vector2f(360,280));
    Alcantarilla *alc2 = new Alcantarilla( sf::Vector2f(360,665));
    alcantarillas.push_back(alc1);
    alcantarillas.push_back(alc2);
}

int Mundo::getTime()
{
    return tiempo;
}

void Mundo::initPuntosEntrega()
{
    /// Inicializo la textura del punto de entrega
    texture.loadFromFile("assets/PowerUps/power.png");
    if (!texture.loadFromFile("assets/PowerUps/power.png"))
    {
        std::cout<< "Error cargando la imagen PowerUps.png"<<std::endl;
        exit(0);
    }
    /// Pongo el sprite del punto de entrega
    puntoEntrega = new sf::Sprite();
    puntoEntrega->setTexture(texture);
    puntoEntrega->setTextureRect(sf::IntRect(15,16,88,89));
    puntoEntrega->setOrigin(88/2,89/2);
    puntoEntrega->setScale(0.4,0.4);

    /// Situo los puntos de entrega disponibles
    puntosEntrega.push_back(sf::Vector2f(360,200));
    puntosEntrega.push_back(sf::Vector2f(360,500));

    puntoEntrega->setPosition(puntosEntrega[0]);
}

void Mundo::initItems()
{
    /// Creo un item de cada tipo en una posicion determinada con un tiempo de
    /// vida y de generacion
    /// NOTA: El numero de powerUps del mapa se determina en este metodo, ya que el tipo se generara
    /// aleatoriamente.
    Item *vida1 = new Item(1, sf::Vector2f(360,150), 2, 5);
    items.push_back(vida1);
    Item *turbo = new Item(2, sf::Vector2f(420,425), 2,10);
    items.push_back(turbo);
    Item *tiempo = new Item(3, sf::Vector2f(100,425), 2,10);
    items.push_back(tiempo);
    Item *inivisibilidad = new Item(4, sf::Vector2f(100,280), 2,10);
    items.push_back(inivisibilidad);
    /// TODO: crear uno mas de cada tipo para que inicialmente haya powerUps de todos los tipos
    /*Item *levitar = new Item(5, sf::Vector2f(), 2,10);
    items.push_back(levitar);
    Item *imparable = new Item(6, sf::Vector2f(), 2,10);
    items.push_back(imparable);*/
}

Mundo::~Mundo()
{
    //dtor
}
