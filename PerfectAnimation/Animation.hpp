#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>

class Animation
{
protected:
	sf::Vector2i m_currentIndex;
	sf::Sprite* m_targetSprite;

public:
	Animation();
	Animation(sf::Sprite* targetSprite);

	virtual void setActualTexture() = 0;
	virtual unsigned int getSizeCurrentLine() = 0;

	virtual bool increaseIndice();
	virtual void restart();
	virtual void setStateAnimation(int indexLine);

	void setTargetSprite(sf::Sprite* targetSprite);

	virtual double getActualTimeFrame() = 0;
};