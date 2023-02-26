#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "EECSGE/Core.hpp"
#include "EECSGE/Graphics.hpp"

namespace eecsge {
    class AnimationSystem : public System {
        public:
            void Update();
    };
}