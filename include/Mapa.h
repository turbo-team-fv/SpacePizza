#ifndef MAPA_H
#define MAPA_H

#include <string>
#include <iostream>

#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Mapa
{
    public:
        Mapa();
        void load();
        void setTileMapSprites();
        void draw(RenderWindow * window);

    private:
        Texture* mapTexture;
        Sprite*** spriteSet;
        Sprite ****tilemapSprite;

        int numLayers = 0;
        int tileWidth = 0;
        int tileHeight = 0;
        int width = 0;
        int height = 0;
        int tilesetColumns = 0;
        const char * textureFileName;
        int ***tileMap; /// tilemap con los gid de el tmx, matriz en 3D

        void printTileMap();

};

#endif // MAPA_H
