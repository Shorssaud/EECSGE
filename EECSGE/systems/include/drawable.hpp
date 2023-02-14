#pragma once
#include "EECSGE/core/include/System.hpp"
#include <SFML/Graphics.hpp>

class DrawSystem : public System {
    public:
        void DrawEntities(sf::RenderWindow *window);
};