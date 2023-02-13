#pragma once
#include "components/movement.hpp"
#include "components/transform.hpp"
#include "core/include/System.hpp"

class MovementSystem : public System {
    public:
        void Update();
};