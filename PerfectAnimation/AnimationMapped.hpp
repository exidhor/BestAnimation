#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>

class AnimationMapped
{
protected:
	sf::Sprite* m_spriteTarget;
	sf::Vector2i m_indexCurrentTextureRect; // x -> abs, y -> ord

public:
	AnimationMapped(sf::Sprite *spriteTarget);

	virtual void restart() = 0;
	virtual void setTexture(int indexLine) = 0;
	virtual void actualize() = 0;
};