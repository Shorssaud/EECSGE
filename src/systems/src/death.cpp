#include "systems/include/death.hpp"
#include "core/include/Coordinator.hpp"

extern Coordinator gCoordinator;

void DeathSystem::Update()
{
    for (auto const& entity : mEntities) {
        auto health = gCoordinator.GetComponent<Health>(entity);
        if (health.health <= 0) {
            gCoordinator.DestroyEntity(entity);
        }
    }
}