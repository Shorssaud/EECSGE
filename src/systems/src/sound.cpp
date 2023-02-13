#include "systems/include/sound.hpp"
#include "components/sound.hpp"
#include "core/include/Coordinator.hpp"
extern Coordinator gCoordinator;

void SoundSystem::playsounds() {
    for (auto entity : mEntities) {
        auto& sound = gCoordinator.GetComponent<Sound>(entity);
        if (sound.play) {
            sound.play = false;
            sound.sound.play();
        }
    }
}