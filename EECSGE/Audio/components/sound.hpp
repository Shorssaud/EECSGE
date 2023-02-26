#pragma once
#include <SFML/Audio.hpp>

// Be warned the sound must have a initialized soundbuffer
namespace eecsge {
    struct Sound {
        sf::Sound sound;
        bool play;
    };
}