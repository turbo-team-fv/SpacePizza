#include "Mapa.h"
#include "../lib/tinyxml/tinyxml2.h"

using namespace tinyxml2;

Mapa::Mapa()
{
    mapTexture = new Texture();

    load();
}

void Mapa::load()
{

    XMLDocument doc;
    XMLError error = doc.LoadFile("assets/maps/MapaPrueba.tmx");

    if(error)
    {
        cout << "Error reading tmx file" << endl;
        exit(0);
    }

    XMLElement * map = doc.FirstChildElement("map");
    map->QueryIntAttribute("width", &width);
    map->QueryIntAttribute("height", &height);
    map->QueryIntAttribute("tilewidth", &tileWidth);
    map->QueryIntAttribute("tileheight", &tileHeight);

//    cout<<"Width: " << width << " Height: " << height <<endl;
//    cout<<"Tilewidth: " << tileWidth << " Tileheight: " << tileHeight <<endl;

    XMLElement * tileset = map->FirstChildElement("tileset");
    tileset->QueryIntAttribute("columns", &tilesetColumns);

    XMLElement * img = tileset->FirstChildElement("image");
    img->QueryStringAttribute("source", &textureFileName);

    const char * filePath = "assets/maps/";

    char * fullText = new char[strlen(filePath)+strlen(textureFileName)+1];
    strcpy(fullText,filePath);
    strcat(fullText,textureFileName);

    mapTexture->loadFromFile(fullText);

    XMLElement *layer = map->FirstChildElement("layer");
    while(layer)
    {
        numLayers++;
        layer = layer->NextSiblingElement("layer");
    }

    // inicializamos la matriz de gids que tiene nuestor mapa
    tileMap = new int**[numLayers];
    for(int i = 0; i < numLayers; i++)
    {
        tileMap[i] = new int *[height];
    }
    for(int l = 0; l < numLayers; l++)
    {
        for(int y = 0; y < height; y++)
        {
            tileMap[l][y] = new int[width];
        }
    }

    layer = map->FirstChildElement("layer");
    XMLElement * tile ;
    while(layer)
    {
        tile = layer->FirstChildElement("data")->FirstChildElement("tile");

        for (int l = 0; l < numLayers; l++)   // para cada capa del mapa
        {
            for(int y = 0; y < height; y++)   // para cada fila del tilemap
            {
                for(int x = 0; x < width; x++)
                {

                    tile->QueryIntAttribute("gid", &tileMap[l][y][x]);
                    tile = tile->NextSiblingElement("tile");
                }
            }
        }
        layer = layer->NextSiblingElement("layer");
    }


    // for testing
    // printTileMap();

    setTileMapSprites();
}

void Mapa::printTileMap()
{
    for(int l = 0; l < numLayers; l++)
    {
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {
                cout << tileMap[l][y][x] << ", ";
            }
            cout << endl;
        }
    }
}

void Mapa::setTileMapSprites()
{

    tilemapSprite = new Sprite***[numLayers];

    for (int l = 0; l < numLayers; l++)
    {
        tilemapSprite[l] = new sf::Sprite**[height];
    }

    for(int l=0; l < numLayers; l++)
    {
        for(int y = 0; y < height; y++)
        {
            tilemapSprite[l][y] = new Sprite*[width];
            for(int x = 0; x< width; x++)
            {
                tilemapSprite[l][y][x] = new Sprite();
            }
        }
    }

    for(int l = 0; l < numLayers; l++)
    {
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {

                int gid = tileMap[l][y][x]-1;

                if(gid >= 0)
                {
                    int xAux=gid%tilesetColumns, yAux=gid/tilesetColumns;

                    tilemapSprite[l][y][x] = new Sprite(*mapTexture);
                    tilemapSprite[l][y][x]->setTextureRect(IntRect(xAux*tileWidth + (xAux-1) * 1, yAux*tileHeight + (yAux-1) * 1, tileWidth + 1, tileHeight + 1));
                    tilemapSprite[l][y][x]->setPosition(x*(tileWidth) - 1, y*(tileHeight) - 1);
                } else {
                    tilemapSprite[l][y][x] = NULL;
                }
            }
        }
    }
}

void Mapa::draw(RenderWindow * window)
{
    for(int l = 0; l < numLayers; l++)
    {
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {
                if(tilemapSprite[l][y][x] != NULL)
                {
                    window->draw(*tilemapSprite[l][y][x]);
                }
            }
        }
    }
}

