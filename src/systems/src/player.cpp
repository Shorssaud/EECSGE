/*
** EPITECH PROJECT, 2022
** B-CPP-500-BAR-5-2-rtype-shaun.orssaud
** File description:
** player_system.cpp
*/

#include "core/include/Coordinator.hpp"
#include "systems/include/player.hpp"
#include "components/input.hpp"
#include "components/transform.hpp"
#include "components/drawable.hpp"
#include "components/movement.hpp"
#include "components/collision.hpp"
#include "components/health.hpp"

extern Coordinator gCoordinator;

void PlayerSystem::ManagePresses(sf::Keyboard::Key key, Movement &movement, Transform &transform)
{
    switch (key)
    {
    case sf::Keyboard::Up:
        movement.velocity.y = -1;
        break;
    case sf::Keyboard::Down:
        movement.velocity.y = 1;
        break;
    case sf::Keyboard::Left:
        movement.velocity.x = -1;
        break;
    case sf::Keyboard::Right:
        movement.velocity.x = 1;
        break;
    case sf::Keyboard::Space:
        Shoot(transform, movement);
        break;
    default:
        break;
    }
}

void PlayerSystem::ManageReleases(sf::Keyboard::Key key, Movement &movement)
{
    switch (key)
    {
    case sf::Keyboard::Up:
        movement.velocity.y = 0;
        break;
    case sf::Keyboard::Down:
        movement.velocity.y = 0;
        break;
    case sf::Keyboard::Left:
        movement.velocity.x = 0;
        break;
    case sf::Keyboard::Right:
        movement.velocity.x = 0;
        break;
    default:
        break;
    }
}

void PlayerSystem::Shoot(Transform &transform, Movement &movement)
{
    Entity bullet = gCoordinator.CreateEntity();
    gCoordinator.AddComponent<Movement>(bullet,
    Movement{
        sf::Vector2f{1, movement.velocity.y},
        sf::Vector2f{0, 0},
    });
    sf::Texture *texture = new sf::Texture;
    (void) texture->loadFromFile("assets/missing.png");
    sf::Sprite sprite(*texture);
    gCoordinator.AddComponent<Drawable>(bullet,
    Drawable{
        texture,
        sprite,
    });
    gCoordinator.AddComponent<Transform>(bullet,
    Transform{
        transform.position,
        sf::Vector2f(transform.position.x + sprite.getGlobalBounds().width,
                    transform.position.y - sprite.getGlobalBounds().height),
        sf::Vector2f(0, 0),
        sf::Vector2f(1, 1),
    });
    gCoordinator.AddComponent<Collision>(bullet,
    Collision{
        COLLISION_TYPE_BULLET
    });
    gCoordinator.AddComponent<Health>(bullet,
    Health{
        1,
    });

}

void PlayerSystem::Update(sf::Event event)
{
    float speed = 1;
    for (auto const &entity : mEntities)
    {
        auto &inputKeys = gCoordinator.GetComponent<InputKeys>(entity);
        auto &movement = gCoordinator.GetComponent<Movement>(entity);
        auto &transform = gCoordinator.GetComponent<Transform>(entity);
        if (event.type == sf::Event::KeyPressed)
            ManagePresses(event.key.code, movement, transform);
        if (event.type == sf::Event::KeyReleased)
            ManageReleases(event.key.code, movement);
    }
}
