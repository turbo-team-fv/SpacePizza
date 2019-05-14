#include "Mundo.h"
#include "Juego.h"
#include "Car.h"
#include "Path.h"
Mundo::Mundo()
{
    //ctor
    ptoEntrgaActual = 0;
    pizzas = 0;
    entregando = false;
    reparto_time = 30;
    puntuacion = 0;
    tiempo = 10;

    /**ELEMENTOS**/
    mapa = new Mapa();
    p1 = new Jugador();

    clock1 = new Clock();
    time1 = new Time();
    player_lifes = p1->getVidas();

    /** COCHES Y PATHS**/
    DeployCarPaths();
    DeployCars();
    /**********/

    /** HUD, vista and minimap stuff **/
    warning=new Popup("assets/hud/popups/WARNING.png",2);
    warning->getSprite()->addFrame(sf::IntRect(0,0,410,114),0);
    pizza=new Popup("assets/hud/popups/PIZZA.png",2);
    pizza->getSprite()->addFrame(sf::IntRect(2,2,238,118),0);

    txt_pizza = new Texture();
    txt_pizza -> loadFromFile("assets/hud/pizza2.png");

    radio4 = new Texture();
    radio4 -> loadFromFile("assets/Radio/LEKTRO.png");
    radio1 = new Texture();
    radio1 -> loadFromFile("assets/Radio/FUNKY.png");
    radio3 = new Texture();
    radio3 -> loadFromFile("assets/Radio/SANTOS.png");
    radio2 = new Texture();
    radio2 -> loadFromFile("assets/Radio/machetaso.png");

    s_radio1 = new Sprite(*radio1);
    s_radio2 = new Sprite(*radio2);
    s_radio3 = new Sprite(*radio3);
    s_radio4 = new Sprite(*radio4);
    s_radio1->setScale(0.4,0.3);
    s_radio2->setScale(0.4,0.3);
    s_radio3->setScale(0.4,0.3);
    s_radio4->setScale(0.4,0.3);


    txt_hud1 = new Texture();
    txt_hud1 -> loadFromFile("assets/hud/hudtime.png");
    txt_hud2 = new Texture();
    txt_hud2 -> loadFromFile("assets/hud/pizzas.png");
    spr_pizza = new Sprite(*txt_pizza);
    spr_pizza -> setScale(20.f/270, 20.f/255);
    spr_hud1 = new Sprite(*txt_hud1);
    spr_hud1 -> setScale(0.32, 0.3);
    spr_hud2 = new Sprite(*txt_hud2);
    spr_hud2 -> setScale(0.4, 0.3);

    font_numbers = new Font();
    font_numbers ->loadFromFile("assets/hud/m42.TTF");
    font_player_lifes = new Font();
    font_player_lifes ->loadFromFile("assets/hud/HeartsSt.ttf");
    text_num_pizzas = new Text();
    text_num_pizzas -> setFont(*font_numbers);
    text_num_pizzas -> setCharacterSize(10);
    text_time = new Text();
    text_time -> setFont(*font_numbers);
    text_time -> setCharacterSize(10);
    text_player_lifes = new Text();
    text_player_lifes -> setFont(*font_player_lifes);
    text_player_lifes -> setCharacterSize(12);
    text_player_lifes -> setColor(Color::Red);

    txt_pwupHUD_empty = new Texture();
    txt_pwupHUD_empty -> loadFromFile("assets/hud/powerups/Hud_empty.png");
    txt_pwupHUD_escudo = new Texture();
    txt_pwupHUD_escudo -> loadFromFile("assets/hud/powerups/Hud_escudo.png");
    txt_pwupHUD_invisibilidad = new Texture();
    txt_pwupHUD_invisibilidad -> loadFromFile("assets/hud/powerups/Hud_invisibilidad.png");
    txt_pwupHUD_tiempo = new Texture();
    txt_pwupHUD_tiempo -> loadFromFile("assets/hud/powerups/Hud_tiempo.png");
    txt_pwupHUD_velocidad = new Texture();
    txt_pwupHUD_velocidad -> loadFromFile("assets/hud/powerups/Hud_velocidad.png");
    txt_pwupHUD_vida = new Texture();
    txt_pwupHUD_vida -> loadFromFile("assets/hud/powerups/Hud_vida.png");
    txt_pwupHUD_levitar = new Texture();
    txt_pwupHUD_levitar -> loadFromFile("assets/hud/powerups/Hud_levitar.png");

    pwupHUD_ative = new RectangleShape({50,45});
    pwupHUD_ative -> setTexture(txt_pwupHUD_empty);

    minimap_player = new CircleShape(20);
    minimap_player -> setFillColor(sf::Color(150, 50, 250));
    minimap_player -> setOutlineThickness(10);
    minimap_player -> setOutlineColor(sf::Color(250, 150, 100));

    minimap_pizza = new CircleShape(30);
    minimap_pizza -> setFillColor(sf::Color(100, 250, 50));
    minimap_pizza -> setOutlineThickness(10);
    minimap_pizza -> setOutlineColor(sf::Color(50, 150, 250));

    // Vista
    vista = new View();
    vista -> reset(sf::FloatRect(p1->getPhysicsState()->getActualState().x,p1->getPhysicsState()->getActualState().y, 300, 200));
    vista->setCenter((float)p1->getPhysicsState()->getActualState().x, (float)p1->getPhysicsState()->getActualState().y);
    vista->setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    //vista->zoom(0.8f);

    /// Minimap
    minimap = new View();
    minimap->setViewport(sf::FloatRect(0.75f, 0.75f, 0.25f, 0.25f));

    ///inits
    initPuntosEntrega();
    initItems();
    initAlcantarillas();
    calcularPuntuacionVariable();

}

/// Metodo para inizializar las Alcantarillas del Mundo
void Mundo::initAlcantarillas()
{
    Alcantarilla *alc1 = new Alcantarilla(sf::Vector2f(585,200));
    Alcantarilla *alc2 = new Alcantarilla( sf::Vector2f(585,650));
    Alcantarilla *alc3 = new Alcantarilla(sf::Vector2f(985,650));
    Alcantarilla *alc4 = new Alcantarilla( sf::Vector2f(860,1120));
    alcantarillas.push_back(alc1);
    alcantarillas.push_back(alc2);
    alcantarillas.push_back(alc3);
    alcantarillas.push_back(alc4);
}
void Mundo::initPuntosEntrega()
{
    /// Inicializo la textura del punto de entrega
    texture.loadFromFile("assets/PowerUps/power.png");
    if (!texture.loadFromFile("assets/PowerUps/powerUps.png"))
    {
        std::cout<< "Error cargando la imagen PowerUps.png"<<std::endl;
        exit(0);
    }
    /// Pongo el sprite del punto de entrega
    puntoEntrega = new sf::Sprite();
    puntoEntrega->setTexture(texture);
    puntoEntrega->setTextureRect(sf::IntRect(254,136,92,91));
    puntoEntrega->setOrigin(92/2,91/2);
    puntoEntrega->setScale(0.4,0.4);

    /// Situo los puntos de entrega disponibles
    puntosEntrega.push_back(sf::Vector2f(1080,210));
    puntosEntrega.push_back(sf::Vector2f(245,455));
    puntosEntrega.push_back(sf::Vector2f(940,665));
    puntosEntrega.push_back(sf::Vector2f(280,910));
    puntosEntrega.push_back(sf::Vector2f(710,1210));
    puntosEntrega.push_back(sf::Vector2f(1175,1235));

    puntoEntrega->setPosition(puntosEntrega[ptoEntrgaActual]);
}

void Mundo::initItems()
{
    /// Creo un item de cada tipo en una posicion determinada con un tiempo de
    /// vida y de generacion
    /// NOTA: El numero de powerUps del mapa se determina en este metodo, ya que el tipo se generara
    /// aleatoriamente.
    Item *item1     = new Item(1, sf::Vector2f(855,200), 5,10);
    Item *item2     = new Item(2, sf::Vector2f(445,475), 8,15);
    Item *item3     = new Item(3, sf::Vector2f(835,475), 10,20);
    Item *item4     = new Item(4, sf::Vector2f(1175,470), 5,10);
    Item *item5     = new Item(5, sf::Vector2f(580,925), 7,12);
    Item *item6     = new Item(1, sf::Vector2f(1175,925), 5,12);
    Item *item7     = new Item(2, sf::Vector2f(280,1065), 8,16);
    Item *item8     = new Item(3, sf::Vector2f(980,1100), 5,10);
    Item *item9     = new Item(4, sf::Vector2f(515,1230), 7,15);
    Item *item10    = new Item(5, sf::Vector2f(775,650), 5,10);


    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    items.push_back(item4);
    items.push_back(item5);
    items.push_back(item6);
    items.push_back(item7);
    items.push_back(item8);
    items.push_back(item9);
    items.push_back(item10);

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
        if((abs(p1->getSprite()->getRenderPos().x-e1[en]->getSprite()->getRenderPos().x)<rango)
                &&(abs(p1->getSprite()->getRenderPos().y-e1[en]->getSprite()->getRenderPos().y)<rango))
        {
            if(e1[en]->getAtaque())
            {
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
            if((abs(p1->getSprite()->getRenderPos().x-e1[en]->getSprite()->getRenderPos().x)<rango)
                    &&(abs(p1->getSprite()->getRenderPos().y-e1[en]->getSprite()->getRenderPos().y)<rango))
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
        for(unsigned en=0; en< e1.size(); en++)
        {

            e1[en]->setVision(false);
            e1[en]->setAtaque(false);
            e1[en]->setActitud(0);
        }
    }
}



sf::Vector2f Mundo::colisionesMapa()
{

    float offset=0;
    sf::Vector2f bounce(0,0);

    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[0])!=0)
    {
        bounce.y=-1;
    }

    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[1])!=0)
    {
        bounce.x=1;
    }

    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[2])!=0)
    {

        bounce.x=-1;
    }

    if(mapa->checkearColision(p1->getPhysicsState()->getColliders()[3])!=0)
    {
        bounce.y=1;
    }

    if(p1->checkEstado()!=3){
    for(unsigned int i = 0; i<carsVector.size(); i++)
    {
        if((p1->getPhysicsState()->getColliders()[0].intersects(carsVector[i]->getSprite()->getGlobalBounds()))&&
                (p1->getPhysicsState()->getColliders()[0].top-carsVector[i]->getSprite()->getGlobalBounds().top!=0))
        {
            bounce.y=-1;
        }
        if((p1->getPhysicsState()->getColliders()[1].intersects(carsVector[i]->getSprite()->getGlobalBounds()))&&
                (p1->getPhysicsState()->getColliders()[1].top-carsVector[i]->getSprite()->getGlobalBounds().top!=0))
        {
            bounce.x=1;
        }
        if((p1->getPhysicsState()->getColliders()[2].intersects(carsVector[i]->getSprite()->getGlobalBounds()))&&
                (p1->getPhysicsState()->getColliders()[2].top-carsVector[i]->getSprite()->getGlobalBounds().top!=0))
        {
            bounce.x=-1;
        }
        if((p1->getPhysicsState()->getColliders()[3].intersects(carsVector[i]->getSprite()->getGlobalBounds()))&&
                (p1->getPhysicsState()->getColliders()[3].top-carsVector[i]->getSprite()->getGlobalBounds().top!=0))
        {
            bounce.y=1;
        }

    }
    }

    if(mapa->estaEnCesped(p1->getPhysicsState()->getColliders()[0]))
    {
        p1->setCesped(true);
        ControladorSonido::getInstance()->playCesped();
    }
    else
    {
        p1->setCesped(false);
        ControladorSonido::getInstance()->stopCesped();
    }

    return bounce;

}

void Mundo::colisionAlcantarilla(bool eRight, bool eLeft, bool eUp, bool eDown)
{

/// Colisiones con las alcantarillas
    for( int i = 0; i < alcantarillas.size(); i++ )
    {
        if(p1->getPhysicsState()->getColliders()[0].intersects(alcantarillas[i]->getSprite().getGlobalBounds()))
        {

            /**Comprobamos destino**/
            if(i == alcantarillas.size() -1)
            {
                if(eRight)
                    p1->getPhysicsState()->MoveTo(sf::Vector2f(alcantarillas[0]->getPosInicial().x+30, (double)alcantarillas[0]->getPosInicial().y));

                else if(eLeft)
                    p1->getPhysicsState()->MoveTo(sf::Vector2f(alcantarillas[0]->getPosInicial().x-30, (double)alcantarillas[0]->getPosInicial().y));

                else if(eDown)
                    p1->getPhysicsState()->MoveTo(sf::Vector2f(alcantarillas[0]->getPosInicial().x, (double)alcantarillas[0]->getPosInicial().y+30));

                else if(eUp)
                    p1->getPhysicsState()->MoveTo(sf::Vector2f(alcantarillas[0]->getPosInicial().x, (double)alcantarillas[0]->getPosInicial().y-30));


            }
            else
            {
                if(eRight)
                    p1->getPhysicsState()->MoveTo(sf::Vector2f(alcantarillas[i+1]->getPosInicial().x+30, (double)alcantarillas[i+1]->getPosInicial().y));

                else if(eLeft)
                    p1->getPhysicsState()->MoveTo(sf::Vector2f(alcantarillas[i+1]->getPosInicial().x-30, (double)alcantarillas[i+1]->getPosInicial().y));

                else if(eDown)
                    p1->getPhysicsState()->MoveTo(sf::Vector2f(alcantarillas[i+1]->getPosInicial().x, (double)alcantarillas[i+1]->getPosInicial().y+30));

                else if(eUp)
                    p1->getPhysicsState()->MoveTo(sf::Vector2f(alcantarillas[i+1]->getPosInicial().x, (double)alcantarillas[i+1]->getPosInicial().y-30));
            }

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
            ControladorSonido::getInstance()->playPowerUp();
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
                ControladorSonido::getInstance()->playTurbo();
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

            case 5:
                // Colisiona con uno de tipo Levitar => Quitar colisiones edificios
                std::cout<<"Colision con un powerUp de tipo Levitar"<<std::endl;
                items[i]->restartPowerUp();
                p1->setEstado(3);
                p1->restartEstado();
                break;
            }
        }
    }

}
void Mundo::EnemigoGenerator()
{

    if(SpawnEnemigo.getElapsedTime().asSeconds()>20&&e1.size()<10) ///ESTO SE HARA CON LA PUNTUACION Y NO CON EL TIEMPO
        //if(SpawnEnemigo_b&&e1.size()<10)
    {
        Enemigo *e= new Enemigo();
        e->getPhysicsState()->MoveTo(sf::Vector2f(rand() % 800 + 1,rand() % 800 + 1));
        SpawnEnemigo.restart();
        SpawnEnemigo_b=false;
        e1.push_back(e);
        warning->throwPopup();

    }
}

void Mundo::checkPuntoEntrega()
{

    if(puntoEntrega->getGlobalBounds().intersects(p1->getSprite()->getActualSprite()->getGlobalBounds()))
    {
        if(entregando == false )
        {
            // Empiezo contar tiempo


            entregando = true;
            clockEntrega.restart();
            /// TODO: Aqui se inicializa la animacion de que este 2 segundos en el pto entrega
        }
        if((int)clockEntrega.getElapsedTime().asSeconds() == 2)
        {
            pizza->setPosition(p1->getSprite()->getRenderPos());
            pizza->throwPopup();
            //SpawnEnemigo.restart();
            SpawnEnemigo_b=true;
            // Permanece 2 segundos dentro del punto de entrega => se genera el nuevo
            int nextPos = rand() % (puntosEntrega.size()-1);
            std::cout<<"Muestro la pos aleatoria para el pto entrega"<<std::endl;
            std::cout<<nextPos<<std::endl;
            /// actualizo la puntuacion del jugador => de momento se almacena en el Mundo
            //p1->puntuacion + puntosPorDistancia;
            puntuacion += puntosPorDistancia;
            /// Aumento el tiempo de bonificacion al juego
            reparto_time += tiempoBonificacion;
            while(nextPos == ptoEntrgaActual)
            {
                nextPos = rand() % (puntosEntrega.size()-1);
            }
            puntoEntrega->setPosition(puntosEntrega[nextPos]);
            ptoEntrgaActual = nextPos;
            pizzas++;
            calcularPuntuacionVariable();
        }
    }
    else
    {
        entregando = false;
        clockEntrega.restart();
        /// TODO: Aqui se reinicia la animacion de que este 2 segundos en el pto entrega
    }
    // colisionAlcantarilla(eRight,eLeft, eUp, eDown);

}

void Mundo::procesarInteraccion(bool eRight, bool eLeft, bool eUp, bool eDown)
{
    visionIA();
    atacaIA();
    colisionItems();
    checkPuntoEntrega();
    colisionAlcantarilla(eRight,eLeft, eUp, eDown);


}
/// Metodo que calcula la puntuacion del siguiente punto de entrega en funcion de la distancia
/// entre el jugador y el siguiente punto de entrega
void Mundo::calcularPuntuacionVariable()
{
    sf::Vector2f posJugador = p1->getPhysicsState()->getActualState();
    sf::Vector2f posPtoEntrega = puntosEntrega[ptoEntrgaActual];

    std::cout<<(posJugador.x - posPtoEntrega.x)<<std::endl;
    /*float x = (float)(posJugador[0] - posPtoEntrega.x);
    float y = (float)(posJugador[1] - posPtoEntrega.y);*/
    sf::Vector2f vectorDistancia = posJugador-posPtoEntrega;
    // Calculo el modulo del vector distnacia para obetener la distancia

    distanciaPtoEntrega = sqrt(pow(vectorDistancia.x,2)+ pow(vectorDistancia.y,2));

    std::cout<<"Muestro la distancia entre el pto de entrega y el jugador"<<std::endl;
    std::cout<<distanciaPtoEntrega<<std::endl;

    puntosPorDistancia = (int)(distanciaPtoEntrega * 0,5);
    calcularTiempoBonificacion();
}

/// Metodo para calcular le tiempo de bonificacion en funcion de la distancia a la que
/// se encentre el jugador y el ptoentrega

void Mundo::calcularTiempoBonificacion()
{
    /// calcula el tiempo que tardaria en ir en linea recta al ptoEntrega => 50 es el valor de potencia
    /// del jugador.
    tiempoBonificacion = (int)distanciaPtoEntrega / 60;
    std::cout<<"Muestro el tiempo de bonificacion para el pto entrega"<<std::endl;
    std::cout<<tiempoBonificacion<<std::endl;
}

int Mundo::getTime()
{
    return tiempo;
}

void Mundo::updateMundo(bool eRight, bool eLeft, bool eUp, bool eDown, sf::Time t)
{
    sf::Vector2f bounce=colisionesMapa();
    EnemigoGenerator();

    procesarInteraccion(eRight,eLeft,eUp,eDown);
    p1->updateJugador(eRight,eLeft,eUp,eDown,bounce,t);


    for(unsigned en=0; en< e1.size(); en++)
    {

        e1[en]->updateEnemigo(p1->getPhysicsState()->getActualState(),t);

        int distanciaEnemigo = std::sqrt(std::pow(e1[en]->getPhysicsState()->getActualState().x - p1->getPhysicsState()->getActualState().x, 2) + std::pow(e1[en]->getPhysicsState()->getActualState().y - p1->getPhysicsState()->getActualState().y, 2));

        float factorVolumen = 0;

        if(distanciaEnemigo < 500)
            factorVolumen = ((float)500 - (float)distanciaEnemigo) / (float)500;

        e1[en]->setVolumen(factorVolumen * 210);
    }
    /**coches**/
    for(unsigned int i = 0; i<carsVector.size(); i++)
        carsVector[i]->Update(t);

//    if(p1->getPhysicsState()->getVel().x > 0 && p1->getPhysicsState()->getVel().y > 0)
//    {
//        ControladorSonido::getInstance()->playDerrape();
//    }
//    else
//    {
//        ControladorSonido::getInstance()->stopDerrape();
//    }


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
    //ss << setw(2) << setfill('0') << ptoEntrgaActual;
    ss << setw(2) << setfill('0') << pizzas;
    std::stringstream ss1;
    if((reparto_time - (int)time1->asSeconds()) > 60)
    {
        ss1 << setw(2) << setfill('0') << (reparto_time - (int)time1->asSeconds()) - 60;
    }
    else
    {
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
        e1[en]->calcInter(ventana,inter);
    }


    vista->setCenter(p1->getSprite()->getRenderPos().x,p1->getSprite()->getRenderPos().y);///SET CAMERA PLAYER
    ventana->setView(*vista);///SET VIEW PLAYER
    mapa->draw(ventana);



    ventana->draw(*puntoEntrega);
    drawItems(ventana);
    drawAlcantarillas(ventana);
    pizza->drawPopup(ventana,inter);
    p1->drawJugador(ventana,inter);
    // p1->getPhysicsState()->drawColliders(ventana,inter);
    for(unsigned en=0; en< e1.size(); en++)
    {
        e1[en]->drawEnemigo(ventana,inter);
    }

    /**  DIBUJADO DE PATHS Y COCHES **/

    for(size_t i = 0; i < wPaths.size(); i++)
        ventana->draw(wPaths[i]);

    for(size_t i = 0; i < carsVector.size(); i++)
        carsVector[i]->Draw(ventana,inter);

    /***********************/


    /// HUD STUFF

    if(ControladorSonido::getInstance()->getRadioActiva()==0){
    s_radio1 ->setPosition(p1->getSprite()->getRenderPos().x-60,p1->getSprite()->getRenderPos().y+70);
    ventana->draw(*s_radio1);}

    if(ControladorSonido::getInstance()->getRadioActiva()==1){
    s_radio2 ->setPosition(p1->getSprite()->getRenderPos().x-60,p1->getSprite()->getRenderPos().y+70);
    ventana->draw(*s_radio2);}

    if(ControladorSonido::getInstance()->getRadioActiva()==2){
    s_radio3 ->setPosition(p1->getSprite()->getRenderPos().x-60,p1->getSprite()->getRenderPos().y+70);
    ventana->draw(*s_radio3);}

    if(ControladorSonido::getInstance()->getRadioActiva()==3){
    s_radio4 ->setPosition(p1->getSprite()->getRenderPos().x-60,p1->getSprite()->getRenderPos().y+70);
    ventana->draw(*s_radio4);}

    spr_hud1 ->setPosition(p1->getSprite()->getRenderPos().x+63,p1->getSprite()->getRenderPos().y - 95);
    ventana->draw(*spr_hud1);
    spr_hud1 ->setPosition(p1->getSprite()->getRenderPos().x-145,p1->getSprite()->getRenderPos().y - 95);
    ventana->draw(*spr_hud1);
    spr_hud2 ->setPosition(p1->getSprite()->getRenderPos().x-13,p1->getSprite()->getRenderPos().y - 95);
    ventana->draw(*spr_hud2);

    spr_pizza ->setPosition(p1->getSprite()->getRenderPos().x-10,p1->getSprite()->getRenderPos().y - 93);
    ventana->draw(*spr_pizza);

    text_num_pizzas -> setPosition(p1->getSprite()->getRenderPos().x+20,p1->getSprite()->getRenderPos().y - 89);
    ventana->draw(*text_num_pizzas);
    text_time -> setPosition(p1->getSprite()->getRenderPos().x+73,p1->getSprite()->getRenderPos().y - 89);
    ventana->draw(*text_time);
    text_player_lifes -> setPosition(p1->getSprite()->getRenderPos().x-140,p1->getSprite()->getRenderPos().y - 90);
    ventana->draw(*text_player_lifes);


    if(p1-> checkEstado() == 0) pwupHUD_ative -> setTexture(txt_pwupHUD_empty);
    if(p1-> checkEstado() == 1) pwupHUD_ative -> setTexture(txt_pwupHUD_velocidad);
    if(p1-> checkEstado() == 2) pwupHUD_ative -> setTexture(txt_pwupHUD_escudo);
    if(p1-> checkEstado() == 3) pwupHUD_ative -> setTexture(txt_pwupHUD_levitar);
    if(p1-> checkEstado() == 10)
    {}


//    if(p1-> checkEstado() == 3) pwupHUD_ative -> setTexture(txt_pwupHUD_tiempo);
    pwupHUD_ative-> setPosition(p1->getSprite()->getRenderPos().x-150,p1->getSprite()->getRenderPos().y + 55);
    ventana->draw(*pwupHUD_ative);


    ventana->setView(*minimap);///SET VIEW MINIMAP
    // mapa->drawMini(ventana);
    ventana->draw(*puntoEntrega);
    drawItems(ventana);
// p1->drawJugador(ventana,inter);

    minimap_player -> setPosition(p1->getSprite()->getRenderPos().x-40,p1->getSprite()->getRenderPos().y-40);
    ventana->draw(*minimap_player);

    minimap_pizza -> setPosition(puntoEntrega->getPosition().x-50,puntoEntrega->getPosition().y-50);
    ventana->draw(*minimap_pizza);

    vista->setCenter(p1->getSprite()->getRenderPos().x,p1->getSprite()->getRenderPos().y);///SET CAMERA PLAYER
    ventana->setView(*vista);///SET VIEW PLAYER
    warning->setPosition(sf::Vector2f(p1->getSprite()->getRenderPos().x,p1->getSprite()->getRenderPos().y+50));
    warning->drawPopup(ventana,inter);

}

void Mundo::drawAlcantarillas(sf::RenderWindow * ventana)
{


    for(int i = 0; i < alcantarillas.size(); i++ )
    {
        alcantarillas[i]->drawAlcantarilla(ventana);
    }

}

//Despliega todos los paths de los coches.
void Mundo::DeployCarPaths()
{
    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints;//carsPath[0]
    waypoints.push_back(sf::Vector2f(283.0f, 488.0f));
    waypoints.push_back(sf::Vector2f(561.0f, 488.0f));
    waypoints.push_back(sf::Vector2f(561.0f, 622.0f));
    waypoints.push_back(sf::Vector2f(283.0f, 622.0f));

    CreateCarPath(waypoints, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::Yellow);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints2; //carsPath[1]
    waypoints2.push_back(sf::Vector2f(561.0f, 622.0f));
    waypoints2.push_back(sf::Vector2f(283.0f, 622.0f));
    waypoints2.push_back(sf::Vector2f(283.0f, 488.0f));
    waypoints2.push_back(sf::Vector2f(561.0f, 488.0f));

    CreateCarPath(waypoints2, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::Yellow);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints3; //carsPath[2]
    waypoints3.push_back(sf::Vector2f(606.0f, 220.0f));
    waypoints3.push_back(sf::Vector2f(1156.0f, 220.0f));
    waypoints3.push_back(sf::Vector2f(1156.0f, 450.0f));
    waypoints3.push_back(sf::Vector2f(606.0f, 450.0f));

    CreateCarPath(waypoints3, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::Red);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints4; //carsPath[3]
    waypoints4.push_back(sf::Vector2f(1156.0f, 220.0f));
    waypoints4.push_back(sf::Vector2f(1156.0f, 450.0f));
    waypoints4.push_back(sf::Vector2f(606.0f, 450.0f));
    waypoints4.push_back(sf::Vector2f(606.0f, 220.0f));

    CreateCarPath(waypoints4, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::Red);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints5; //carsPath[4]

    waypoints5.push_back(sf::Vector2f(1156.0f, 450.0f));
    waypoints5.push_back(sf::Vector2f(606.0f, 450.0f));
    waypoints5.push_back(sf::Vector2f(606.0f, 220.0f));
    waypoints5.push_back(sf::Vector2f(1156.0f, 220.0f));

    CreateCarPath(waypoints5, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::Red);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints6; //carsPath[4]
    waypoints6.push_back(sf::Vector2f(606.0f, 450.0f));
    waypoints6.push_back(sf::Vector2f(606.0f, 220.0f));
    waypoints6.push_back(sf::Vector2f(1156.0f, 220.0f));
    waypoints6.push_back(sf::Vector2f(1156.0f, 450.0f));

    CreateCarPath(waypoints6, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::Red);
    /** ========================== **/


    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints7;//carsPath[4]
    waypoints7.push_back(sf::Vector2f(561.0f, 940.0f));
    waypoints7.push_back(sf::Vector2f(561.0f, 1040.0f));
    waypoints7.push_back(sf::Vector2f(300.0f, 1040.0f));
    waypoints7.push_back(sf::Vector2f(300.0f, 940.0f));

    CreateCarPath(waypoints7, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::Green);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints8;//carsPath[4]
    waypoints8.push_back(sf::Vector2f(300.0f, 1040.0f));
    waypoints8.push_back(sf::Vector2f(300.0f, 940.0f));
    waypoints8.push_back(sf::Vector2f(561.0f, 940.0f));
    waypoints8.push_back(sf::Vector2f(561.0f, 1040.0f));

    CreateCarPath(waypoints8, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::Green);
    /** ========================== **/


    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints9;//carsPath[0]
    waypoints9.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints9.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints9.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints9.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints9.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints9.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints9.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints9.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints9.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints9.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints9.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints9.push_back(sf::Vector2f(1005.0f, 625.0f));

    CreateCarPath(waypoints9, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints10;//carsPath[0]
    waypoints10.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints10.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints10.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints10.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints10.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints10.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints10.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints10.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints10.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints10.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints10.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints10.push_back(sf::Vector2f(606.0f, 625.0f));

    CreateCarPath(waypoints10, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints11;//carsPath[0]
    waypoints11.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints11.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints11.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints11.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints11.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints11.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints11.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints11.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints11.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints11.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints11.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints11.push_back(sf::Vector2f(606.0f, 900.0f));

    CreateCarPath(waypoints11, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints12;//carsPath[0]
    waypoints12.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints12.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints12.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints12.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints12.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints12.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints12.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints12.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints12.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints12.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints12.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints12.push_back(sf::Vector2f(260.0f, 900.0f));

    CreateCarPath(waypoints12, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints13;//carsPath[0]
    waypoints13.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints13.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints13.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints13.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints13.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints13.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints13.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints13.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints13.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints13.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints13.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints13.push_back(sf::Vector2f(260.0f, 1240.0f));

    CreateCarPath(waypoints13, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints14;//carsPath[0]
    waypoints14.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints14.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints14.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints14.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints14.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints14.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints14.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints14.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints14.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints14.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints14.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints14.push_back(sf::Vector2f(825.0f, 1240.0f));

    CreateCarPath(waypoints14, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints15;//carsPath[0]
    waypoints15.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints15.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints15.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints15.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints15.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints15.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints15.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints15.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints15.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints15.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints15.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints15.push_back(sf::Vector2f(825.0f, 1115.0f));

    CreateCarPath(waypoints15, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints16;//carsPath[0]
    waypoints16.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints16.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints16.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints16.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints16.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints16.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints16.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints16.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints16.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints16.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints16.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints16.push_back(sf::Vector2f(885.0f, 1115.0f));

    CreateCarPath(waypoints16, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints17;//carsPath[0]
    waypoints17.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints17.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints17.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints17.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints17.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints17.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints17.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints17.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints17.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints17.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints17.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints17.push_back(sf::Vector2f(885.0f, 1240.0f));

    CreateCarPath(waypoints17, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints18;//carsPath[0]
    waypoints18.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints18.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints18.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints18.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints18.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints18.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints18.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints18.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints18.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints18.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints18.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints18.push_back(sf::Vector2f(1195.0f, 1240.0f));

    CreateCarPath(waypoints18, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints19;//carsPath[0]
    waypoints19.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints19.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints19.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints19.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints19.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints19.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints19.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints19.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints19.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints19.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints19.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints19.push_back(sf::Vector2f(1195.0f, 900.0f));

    CreateCarPath(waypoints19, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints20;//carsPath[0]
    waypoints20.push_back(sf::Vector2f(1005.0f, 625.0f));
    waypoints20.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints20.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints20.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints20.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints20.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints20.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints20.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints20.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints20.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints20.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints20.push_back(sf::Vector2f(1005.0f, 900.0f));

    CreateCarPath(waypoints20, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/

    /** ESTE BLOQUE CREA UN PATH **/
    std::vector<sf::Vector2f> waypoints21;//carsPath[0]
    waypoints21.push_back(sf::Vector2f(606.0f, 625.0f));
    waypoints21.push_back(sf::Vector2f(606.0f, 900.0f));
    waypoints21.push_back(sf::Vector2f(260.0f, 900.0f));
    waypoints21.push_back(sf::Vector2f(260.0f, 1240.0f));
    waypoints21.push_back(sf::Vector2f(825.0f, 1240.0f));
    waypoints21.push_back(sf::Vector2f(825.0f, 1115.0f));
    waypoints21.push_back(sf::Vector2f(885.0f, 1115.0f));
    waypoints21.push_back(sf::Vector2f(885.0f, 1240.0f));
    waypoints21.push_back(sf::Vector2f(1195.0f, 1240.0f));
    waypoints21.push_back(sf::Vector2f(1195.0f, 900.0f));
    waypoints21.push_back(sf::Vector2f(1005.0f, 900.0f));
    waypoints21.push_back(sf::Vector2f(1005.0f, 625.0f));

    CreateCarPath(waypoints21, 5.0f);
    //Llamada a la funcion que crea el contenido de debug de los paths. (Agrega este que he creado)
    LoadDebugPath(carsPaths.back(), sf::Color::White);
    /** ========================== **/



}

//Crea un path para los coches.
void Mundo::CreateCarPath(const std::vector<sf::Vector2f>& l_wps, float l_pathRadius)
{
    carsPaths.push_back(new Path(l_wps, l_pathRadius));
}

//Genera los shapes para visualizar los puntos de los paths;
void Mundo::LoadDebugPath(Path * path, const sf::Color& color)
{
    std::vector<sf::Vector2f> wps =path->GetWPs();
    for(size_t i = 0; i < wps.size(); i++)
    {
        sf::CircleShape circle;
        circle.setRadius(4.0f);
        circle.setFillColor(color);
        circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
        circle.setPosition(wps[i]);
        this->wps.push_back(circle);
    }

    //wPaths.push_back(ToVertex(wps, color));

}

//Genera la geometria necesaria para pintar los paths.
sf::VertexArray Mundo::ToVertex(const std::vector<sf::Vector2f>& points, const sf::Color& color)
{
    sf::VertexArray vertices(sf::LinesStrip, 0);

    for(std::vector<sf::Vector2f>::const_iterator a = points.begin(); a!= points.end(); a++)
    {
        vertices.append(sf::Vertex(*a, color));
    }
    vertices.append(sf::Vertex(points[0], color));
    wPaths.push_back(vertices);
}

//Devuelve un path de todos los disponibles
Path* Mundo::GetPath()
{
    lastPath++;

    if(lastPath >= carsPaths.size())
    {
        lastPath = 1;
    }

    return carsPaths[lastPath - 1];
}

//Despliega todos los coches.
void Mundo::DeployCars()
{

    CreateCar(normal, sf::Vector2f(322, 279));


}

//Crea un coche de un tipo y en una position determinada.
void Mundo::CreateCar(unsigned int l_type, const sf::Vector2f& l_position)
{
    Path * path = carsPaths[0];
    Path * path2 = carsPaths[1];
    Path * path3 = carsPaths[2];
    Path * path4 = carsPaths[3];
    Path * path5 = carsPaths[4];
    Path * path6 = carsPaths[5];
    Path * path7 = carsPaths[6];
    Path * path8 = carsPaths[7];
    Path * path9 = carsPaths[8];
    Path * path10 = carsPaths[9];
    Path * path11 = carsPaths[10];
    Path * path12 = carsPaths[11];
    Path * path13 = carsPaths[12];
    Path * path14 = carsPaths[13];
    Path * path15 = carsPaths[14];
    Path * path16 = carsPaths[15];
    Path * path17 = carsPaths[16];
    Path * path18 = carsPaths[17];
    Path * path19 = carsPaths[18];
    Path * path20 = carsPaths[19];
    Path * path21 = carsPaths[20];

    carsVector.push_back(new Car(l_type, path->GetWPs()[0], carsPaths[0]));
    carsVector.push_back(new Car(l_type, path2->GetWPs()[0], carsPaths[1]));
    carsVector.push_back(new Car(l_type, path3->GetWPs()[0], carsPaths[2]));
    carsVector.push_back(new Car(l_type, path4->GetWPs()[0], carsPaths[3]));
    carsVector.push_back(new Car(l_type, path5->GetWPs()[0], carsPaths[4]));
    carsVector.push_back(new Car(l_type, path6->GetWPs()[0], carsPaths[5]));
    carsVector.push_back(new Car(l_type, path7->GetWPs()[0], carsPaths[6]));
    carsVector.push_back(new Car(l_type, path8->GetWPs()[0], carsPaths[7]));
    carsVector.push_back(new Car(l_type, path9->GetWPs()[0], carsPaths[8]));
    carsVector.push_back(new Car(l_type, path10->GetWPs()[0], carsPaths[9]));
    carsVector.push_back(new Car(l_type, path11->GetWPs()[0], carsPaths[10]));
    carsVector.push_back(new Car(l_type, path12->GetWPs()[0], carsPaths[11]));
    carsVector.push_back(new Car(l_type, path13->GetWPs()[0], carsPaths[12]));
    carsVector.push_back(new Car(l_type, path14->GetWPs()[0], carsPaths[13]));
    /*carsVector.push_back(new Car(l_type, path15->GetWPs()[0], carsPaths[14]));
    carsVector.push_back(new Car(l_type, path16->GetWPs()[0], carsPaths[15]));
    carsVector.push_back(new Car(l_type, path17->GetWPs()[0], carsPaths[16]));
    carsVector.push_back(new Car(l_type, path18->GetWPs()[0], carsPaths[17]));
    carsVector.push_back(new Car(l_type, path19->GetWPs()[0], carsPaths[18]));
    carsVector.push_back(new Car(l_type, path20->GetWPs()[0], carsPaths[19]));
    carsVector.push_back(new Car(l_type, path21->GetWPs()[0], carsPaths[20]));*/
}

Mundo::~Mundo()
{

    /** HUGOOOOOOOOOOOOOOOOOOOO COCHES Y PATHS **/

    for(size_t i = 0; i < carsVector.size(); i++)
    {
        delete carsVector[i];
    }

    for(size_t i = 0; i < carsPaths.size(); i++)
    {
        delete carsPaths[i];
    }

    carsVector.clear();
    carsPaths.clear();
    wps.clear();
    wPaths.clear();
    /***********************/

}

