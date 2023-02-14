#pragma once

#include "EECSGE/core/include/System.hpp"
#include "EECSGE/components/health.hpp"

class DeathSystem : public System {
    public:
        void Update();
};