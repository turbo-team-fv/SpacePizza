#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

//Calcula el modulo de un vector.
inline float Module(const sf::Vector2f& l_vector)
{
    return std::sqrt(l_vector.x * l_vector.x + l_vector.y * l_vector.y);
}
//Devuelve el vector normalizado.
inline sf::Vector2f Normalize(const sf::Vector2f& l_vector)
{
    float module = Module(l_vector);
    return sf::Vector2f(l_vector.x / module, l_vector.y / module);
}
//Te devuele una vector direccion (normalizado) dados dos puntos de entrada.
inline sf::Vector2f NormalizedDirection(const sf::Vector2f& l_endPoint, const sf::Vector2f& l_startPoint)
{
    return Normalize(l_endPoint - l_startPoint);
}
//Calcula la distancia entre dos vectores.
inline float Distance(const sf::Vector2f& l_endPoint, const sf::Vector2f& l_startPoint)
{
    return Module(l_endPoint - l_startPoint);
}

