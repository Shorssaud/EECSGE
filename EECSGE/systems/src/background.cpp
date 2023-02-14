/*
** EPITECH PROJECT, 2022
** Epitech-Rtype
** File description:
** background.cpp
*/

#include "EECSGE/systems/include/background.hpp"

extern Coordinator gCoordinator;

void BackgroundSystem::Update(void)
{
    for (auto const &entity : mEntities)
    {
        auto &transform = gCoordinator.GetComponent<Transform>(entity);
        auto &drawable = gCoordinator.GetComponent<Drawable>(entity);

        if (transform.position.x < -1280)
            transform.position.x = 1280;

        drawable.sprite.setPosition(transform.position);
    }
}
