/*
** EPITECH PROJECT, 2022
** Epitech-Rtype
** File description:
** background.hpp
*/

#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "core/include/Types.hpp"
#include "core/include/System.hpp"
#include "components/drawable.hpp"
#include "components/transform.hpp"
#include "core/include/Coordinator.hpp"

class BackgroundSystem : public System
{
public:
    void Update(void);
};
