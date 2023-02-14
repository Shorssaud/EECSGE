#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "EECSGE/core/include/Types.hpp"
#include "EECSGE/core/include/System.hpp"
#include "EECSGE/components/drawable.hpp"

class AnimationSystem : public System {
    public:
        void Update(void);
};