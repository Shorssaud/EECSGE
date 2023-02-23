#pragma once
#include "EECSGE/Core.hpp"
#include "EECSGE/Physics.hpp"
#include "EECSGE/Graphics.hpp"
#include <SFML/Graphics.hpp>

class DrawSystem : public System {
    public:
        void DrawEntities(sf::RenderWindow *window);
};