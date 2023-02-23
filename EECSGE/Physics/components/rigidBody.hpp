#pragma once
#include <SFML/Graphics.hpp>

struct RigidBody {
    sf::Vector2i position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f bounds;
	sf::Vector2f rotation;
	sf::Vector2f scale;
    bool hasCollision;
};