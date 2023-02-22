#include "EECSGE/systems/include/animation.hpp"
#include "EECSGE/core/include/Coordinator.hpp"
#include "EECSGE/components/rigidBody.hpp"
extern Coordinator gCoordinator;

void AnimationSystem::Update(void)
{
	for (auto const& entity : mEntities)
	{
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