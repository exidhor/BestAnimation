#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Tile.hpp"
#include "Animation.hpp"

class AnimationPerTile : public Animation
{
private:
	Tile* m_tile;

public:
	AnimationPerTile(Tile* tile);
	AnimationPerTile(sf::Sprite* targetSprite, Tile* tile);
	AnimationPerTile(sf::Texture* tile);

	virtual void setActualTexture();
	
	virtual unsigned int getSizeCurrentLine();
	virtual double getActualTimeFrame();
	sf::IntRect getCurrentTextureRect();
};