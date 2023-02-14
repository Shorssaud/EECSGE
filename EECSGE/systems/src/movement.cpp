#include "EECSGE/systems/include/movement.hpp"
#include "EECSGE/core/include/Coordinator.hpp"
#include "EECSGE/components/movement.hpp"
#include "EECSGE/components/transform.hpp"
extern Coordinator gCoordinator;

void MovementSystem::Update() {
    for (auto entity : mEntities) {
        auto& movement = gCoordinator.GetComponent<Movement>(entity);
        auto& transform = gCoordinator.GetComponent<Transform>(entity);
        transform.position.x += movement.velocity.x;
        transform.position.y += movement.velocity.y;
        movement.velocity.x += movement.acceleration.x;
        movement.velocity.y += movement.acceleration.y;
    }
}