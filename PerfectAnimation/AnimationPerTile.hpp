#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "AnimationMapped.hpp"
#include "TimeAnim.hpp"
#include "Tile.hpp"

class AnimationPerTile : public AnimationMapped
{
protected:
	Tile* m_tile;
	sf::Vector2i m_indexCurrentTextureRect;
	TimeAnim m_timerAnim;

public:
	AnimationPerTile(sf::Sprite* spriteTarget, Tile* tile);

	virtual void restart();
	virtual void setTexture(int indexLine);
	virtual void setActualTexture();

	double getTime(sf::Vector2i const& coord);
	double getActualTime();
};