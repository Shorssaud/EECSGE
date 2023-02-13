#include "systems/include/movement.hpp"
#include "core/include/Coordinator.hpp"
#include "components/movement.hpp"
#include "components/transform.hpp"
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