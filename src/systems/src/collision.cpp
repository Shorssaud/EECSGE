#include "systems/include/collision.hpp"
#include "core/include/Coordinator.hpp"
#include "components/collision.hpp"
#include "components/drawable.hpp"
#include "components/health.hpp"

extern Coordinator gCoordinator;

void CollisionSystem::Update(float dt)
{
    for (auto const& entity1 : mEntities) {
        for (auto const& entity2 : mEntities) {
            if (entity1 == entity2)
                continue;
            auto colltype1 = gCoordinator.GetComponent<Collision>(entity1);
            auto colltype2 = gCoordinator.GetComponent<Collision>(entity2);
            if (colltype1.coltype == colltype2.coltype)
                continue;
            auto drawable1 = gCoordinator.GetComponent<Drawable>(entity1);
            auto drawable2 = gCoordinator.GetComponent<Drawable>(entity2);
            sf::FloatRect drawableBounds1 = drawable1.sprite.getGlobalBounds();
            sf::FloatRect drawableBounds2 = drawable2.sprite.getGlobalBounds();
            if (drawableBounds1.findIntersection(drawableBounds2)) {
                auto health1 = gCoordinator.GetComponent<Health>(entity1);
                auto health2 = gCoordinator.GetComponent<Health>(entity2);
                health1.health -= 1;
                health2.health -= 1;
            }
        }
    }
}