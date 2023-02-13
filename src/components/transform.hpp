#pragma once
#include <SFML/Graphics.hpp>

struct Transform
{
	sf::Vector2f position;
	sf::Vector2f bounds;
	sf::Vector2f rotation;
	sf::Vector2f scale;
};