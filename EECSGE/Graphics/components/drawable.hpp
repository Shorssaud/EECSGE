#pragma once
#include "SFML/Graphics.hpp"

struct Drawable
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect rect;
	sf::Clock rect_clock;
	int rect_timer;
	int rect_width;
	int rect_frames;
	bool is_animated;
};