#include "systems/include/drawable.hpp"
#include "core/include/Coordinator.hpp"
#include "components/drawable.hpp"
#include "components/transform.hpp"
#include "components/movement.hpp"

extern Coordinator gCoordinator;

void DrawSystem::DrawEntities(sf::RenderWindow *window)
{
	for (auto const& entity : mEntities)
	{
		auto& transform = gCoordinator.GetComponent<Transform>(entity);
		auto& movement = gCoordinator.GetComponent<Movement>(entity);
		auto& drawable = gCoordinator.GetComponent<Drawable>(entity);
		drawable.sprite.setPosition(sf::Vector2f{transform.position.x + movement.velocity.x, transform.position.y + movement.velocity.y});

		window->draw(drawable.sprite);
	}
}