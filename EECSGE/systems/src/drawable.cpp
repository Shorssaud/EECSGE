#include "EECSGE/systems/include/drawable.hpp"
#include "EECSGE/core/include/Coordinator.hpp"
#include "EECSGE/components/drawable.hpp"
#include "EECSGE/components/transform.hpp"
#include "EECSGE/components/movement.hpp"

extern Coordinator gCoordinator;

void DrawSystem::DrawEntities(sf::RenderWindow *window)
{
	for (auto const& entity : mEntities)
	{
		auto& transform = gCoordinator.GetComponent<Transform>(entity);
		auto& movement = gCoordinator.GetComponent<Movement>(entity);
		auto& drawable = gCoordinator.GetComponent<Drawable>(entity);
		drawable.sprite.setPosition(sf::Vector2f{transform.position.x + movement.velocity.x, transform.position.y + movement.velocity.y});
		drawable.sprite.setTextureRect(drawable.rect);
		drawable.sprite.setScale(transform.scale);

		window->draw(drawable.sprite);
	}
}