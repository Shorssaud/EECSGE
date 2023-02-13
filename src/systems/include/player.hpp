/*
** EPITECH PROJECT, 2022
** B-CPP-500-BAR-5-2-rtype-shaun.orssaud
** File description:
** player_system.hpp
*/

#pragma once

#include <iostream>
#include <gtest/gtest.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "core/include/System.hpp"

#include "components/input.hpp"
#include "components/movement.hpp"
#include "components/transform.hpp"

class PlayerSystem : public System {
    public:
        void Update(sf::Event event);
    
    private:
        void ManagePresses(sf::Keyboard::Key key, Movement &movement, Transform &transform);
        void ManageReleases(sf::Keyboard::Key key, Movement &movement);
        void Shoot(Transform &transform, Movement &movement);

        FRIEND_TEST(InputTestPRESS, managePresses);
        FRIEND_TEST(InputTestRELEASE, manageReleases);
        FRIEND_TEST(InputTestSHOOT, Shoot);
};