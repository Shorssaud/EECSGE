#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Core.hpp"
#include "Graphics.hpp"

class AnimationSystem : public System {
    public:
        void Update(void);
};