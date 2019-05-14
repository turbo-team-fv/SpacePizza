#pragma once
#include "vector"
#include <SFML/Graphics.hpp>

class Path
{
    friend class Car;

    public:
        Path(const std::vector<sf::Vector2f>& l_waypoints, float l_pathRadius)
        {
            pathSize   = l_waypoints.size();
            pathRadius = l_pathRadius;
            waypoints  = l_waypoints;
        };
        ~Path(){};

        std::vector<sf::Vector2f> GetWPs() const { return waypoints; };
        size_t GetSize() const { return pathSize; };
        float GetRadius() const { return pathRadius; };

    private:
        size_t pathSize;
        float pathRadius;

        std::vector<sf::Vector2f> waypoints;
};
