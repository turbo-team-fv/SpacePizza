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
    XMLError error = doc.LoadFile("assets/maps/testMap.tmx");

    if(error)
    {
        cout << "Error reading tmx file" << endl;
        exit(0);
    }

    XMLElement * map = doc.FirstChildElement("map");
    map->QueryIntAttribute("width", &width);
    map->QueryIntAttribute("height", &height);
    map->QueryIntAttribute("tileWidth", &tileWidth);
    map->QueryIntAttribute("tileHeight", &tileHeight);


    XMLElement * tileset = map->FirstChildElement("tileset");
    XMLElement * img = tileset->FirstChildElement("image");
    img->QueryStringAttribute("source", &textureFileName);

    const char * filePath = "assets/maps/";

    char * fullText = new char[strlen(filePath)+strlen(textureFileName)+1];
    strcpy(fullText,filePath);
    strcat(fullText,textureFileName);

    mapTexture->loadFromFile(fullText);

    XMLElement *layer = map->FirstChildElement("layer");
    while(layer) {
        numLayers++;
        layer = layer->NextSiblingElement("layer");
    }

    // inicializamos la matriz de gids que tiene nuestor mapa
    tileMap = new int**[numLayers];
    for(int i = 0; i < numLayers; i++) {
        tileMap[i] = new int *[height];
    }
    for(int l = 0; l < numLayers; l++) {
        for(int y = 0; y < height; y++) {
            tileMap[l][y] = new int[width];
        }
    }

//    XMLElement *data[0] = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
//
//    for (int l = 0; l < numLayers; l++) { // para cada capa del mapa
//        for(int y = 0; y < height; y++) { // para cada fila del tilemap
//            for(int x = 0; x < width; x++) {
//                data[l]->QueryIntAttribute("gid", &tileMap[l][y][x])
//                data[l] = data[l]->NextSiblingElement("tile");
//            }
//        }
//    }

    layer = map->FirstChildElement("layer");
    XMLElement * tile ;
    while(layer) {
        tile = layer->FirstChildElement("data")->FirstChildElement("tile");

        for (int l = 0; l < numLayers; l++) { // para cada capa del mapa
            for(int y = 0; y < height; y++) { // para cada fila del tilemap
                for(int x = 0; x < width; x++) {
                    tile->QueryIntAttribute("gid", &tileMap[l][y][x]);
                    tile = tile->NextSiblingElement("tile");
                }
            }
        }
        layer = layer->NextSiblingElement("layer");
    }
}

