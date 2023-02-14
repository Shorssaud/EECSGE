#pragma once
#include "EECSGE/components/movement.hpp"
#include "EECSGE/components/transform.hpp"
#include "EECSGE/core/include/System.hpp"

class MovementSystem : public System {
    public:
        void Update();
};