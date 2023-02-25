// create a series of tests which test the animation system and the drawing system
//
// Path: tests/animating_tests.cpp
// Compare this snippet from tests/system_tests.cpp:

#include <iostream>
#include <EECSGE/Core.hpp>
#include <EECSGE/Physics.hpp>
#include <EECSGE/Graphics.hpp>
#include <gtest/gtest.h>
#include <vector>

Coordinator gCoordinator;
TEST(Animation, test_functional)
{
    gCoordinator.Init();

    gCoordinator.RegisterComponent<Drawable>();
    gCoordinator.RegisterComponent<RigidBody>();
    auto draw = gCoordinator.RegisterSystem<DrawSystem>();
    auto animation = gCoordinator.RegisterSystem<AnimationSystem>();

    Signature Dsignature;
    Dsignature.set(gCoordinator.GetComponentType<Drawable>());
    gCoordinator.SetSystemSignature<DrawSystem>(Dsignature);

    Signature Asignature;
    Asignature.set(gCoordinator.GetComponentType<Drawable>());

    gCoordinator.SetSystemSignature<AnimationSystem>(Asignature);

    Entity player = gCoordinator.CreateEntity();
	sf::Texture *player_texture = new sf::Texture();
	sf::Sprite player_sprite = sf::Sprite(*player_texture);
    int player_rect_width = 380;
    int player_rect_timer = 120;
    int player_rect_frames = 2;
    sf::IntRect player_rect = sf::IntRect{{0, 0}, {player_rect_width, 150}};
    player_sprite.setTextureRect(player_rect);
    sf::Clock player_rect_clock;

    gCoordinator.AddComponent(player,
        RigidBody{
            .position = sf::Vector2i(100, 100),
            .velocity = sf::Vector2f(0.0, 0.0),
            .acceleration = sf::Vector2f(0.0, 0.0),
            .bounds = sf::Vector2f(100.0 + player_sprite.getGlobalBounds().width,
                                    100.0 - player_sprite.getGlobalBounds().height),
            .rotation = sf::Vector2f(0.0, 0.0),
            .scale = sf::Vector2f(1, 1)
        });
    gCoordinator.AddComponent(player,
        Drawable{
            player_texture,
            player_sprite,
            player_rect,
            player_rect_clock,
            player_rect_timer,
            player_rect_width,
            player_rect_frames,
        });
    sf::RenderWindow win;
    win.create((sf::VideoMode){1280, 700}, "R-Type");
    int i = 0;
    while (gCoordinator.GetComponent<Drawable>(player).rect.left < 760)
    {
        animation->Update();
        draw->DrawEntities(&win);
        if (gCoordinator.GetComponent<Drawable>(player).rect.left / 380 > i)
            i++;
    }
    std::cerr << i << std::endl;
    EXPECT_EQ(gCoordinator.GetComponent<Drawable>(player).rect.left, 760);
}