#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "AnimationMapped.hpp"
#include "AnimationPerFrame.hpp"

class AnimationArray : public AnimationMapped
{
protected:
	std::vector <AnimationPerFrame*> m_animationArray;
	int m_indexLine;

public:
	AnimationArray(sf::Sprite* spriteTarget, std::vector<AnimationPerFrame*> animationArray);

	virtual void restart();
	virtual void setTexture(int indexLine);
	virtual bool actualize(double time);
	virtual void setActualTexture();
};