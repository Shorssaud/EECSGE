#pragma once

#include "core/include/System.hpp"
#include "components/health.hpp"

class DeathSystem : public System {
    public:
        void Update();
};