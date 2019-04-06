#include "Mapa.h"
#include "../lib/tinyxml/tinyxml2.h"

using namespace tinyxml2;

Mapa::Mapa()
{
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
    cout << fullText << endl;

    mapTexture->loadFromFile(filePath);


}

