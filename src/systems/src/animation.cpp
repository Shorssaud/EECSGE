#include "systems/include/animation.hpp"
#include "core/include/Coordinator.hpp"
#include "components/drawable.hpp"
#include "components/transform.hpp"
#include "components/movement.hpp"
extern Coordinator gCoordinator;

void AnimationSystem::Update(void)
{
	for (auto const& entity : mEntities)
	{
		auto& transform = gCoordinator.GetComponent<Transform>(entity);
		auto& movement = gCoordinator.GetComponent<Movement>(entity);
		auto& drawable = gCoordinator.GetComponent<Drawable>(entity);

        if (drawable.isAnimated == false)
            return;
        if (drawable.rect.left < (drawable.rect_width * drawable.rect_frames)) {
            if (drawable.rect_clock.getElapsedTime().asMilliseconds() >= drawable.rect_timer) {
                drawable.rect.left += drawable.rect_width;
                drawable.rect_clock.restart();
            }
        } else {
            drawable.rect.left = 0;
        }
        drawable.sprite.setTextureRect(drawable.rect);
	}
}