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
#include "EECSGE/core/include/Types.hpp"
#include "EECSGE/core/include/System.hpp"
#include "EECSGE/components/drawable.hpp"
#include "EECSGE/components/transform.hpp"
#include "EECSGE/core/include/Coordinator.hpp"

class BackgroundSystem : public System
{
public:
    void Update(void);
};
