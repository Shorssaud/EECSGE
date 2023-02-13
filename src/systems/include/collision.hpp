#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "core/include/Types.hpp"
#include "core/include/System.hpp"
#include "components/drawable.hpp"

class CollisionSystem : public System {
    public:
        void Update(float dt);
};