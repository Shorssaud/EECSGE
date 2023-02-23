#include "Graphics.hpp"

extern Coordinator gCoordinator;

void DrawSystem::DrawEntities(sf::RenderWindow *window)
{
	for (auto const& entity : mEntities)
	{
		auto& rigidBody = gCoordinator.GetComponent<RigidBody>(entity);
		auto& drawable = gCoordinator.GetComponent<Drawable>(entity);
		drawable.sprite.setPosition(sf::Vector2f{rigidBody.position.x + rigidBody.velocity.x, rigidBody.position.y + rigidBody.velocity.y});
		drawable.sprite.setTextureRect(drawable.rect);
		drawable.sprite.setScale(rigidBody.scale);

		window->draw(drawable.sprite);
	}
}