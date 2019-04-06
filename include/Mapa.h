#ifndef MAPA_H
#define MAPA_H

#include <string>

class Mapa
{
    public:
        Mapa();
        void load(std::string file);

    private:
        int numLayers = 0;
        int ***tileMap; /// tilemap con los gid de el tmx, matriz en 3D



};

#endif // MAPA_H
