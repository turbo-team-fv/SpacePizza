#pragma once
#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>


class Path;

enum CarType
{
    light = 0,
    normal = 1,
    heavy = 2
};

class Car
{
    public:
        Car(unsigned int type, const sf::Vector2f& l_position, Path * l_path);
        ~Car();

        void Init();
        void InitSprite(const sf::IntRect& l_rect);
        void Update(sf::Time elapsedTime);
        void Draw(sf::RenderWindow *w);

        void PathFollowing(sf::Time elapsedTime);
        void Seek(sf::Vector2f l_target, sf::Time elapsedTime);
        void CheckSpriteDirection(const sf::Vector2f& l_dir);

    private:
        unsigned int type;

        // === PATH FOLLOWING === //
        Path * path;
        int direction= 1;
        unsigned int currentWP = 0;
        sf::Vector2f currentTarget;
        sf::Vector2f currentVelocity;
        sf::Vector2f lastVelocity;
        // === STEERING BEHAVIORS === //
        float mass         = 0.0f;
        float force        = 0.0f;
        float maxVelocity  = 0.0;
        // === GRAPHICS === //

        sf::Sprite  * sprite;
        sf::Texture * texture;
        std::map<std::string, sf::IntRect> frames;

        // === DEBUG PATH === //

        sf::CircleShape pathPoints;
};
