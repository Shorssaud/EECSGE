#pragma once
#include "Core.hpp"
#include "Physics.hpp"
#include "Graphics.hpp"
#include <SFML/Graphics.hpp>

class DrawSystem : public System {
    public:
        void DrawEntities(sf::RenderWindow *window);
};