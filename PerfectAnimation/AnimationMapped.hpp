#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "TokenActualizationSituation.hpp"
#include "TimeAnim.hpp"

class AnimationMapped
{
protected:
	sf::Sprite* m_spriteTarget;
	TimeAnim m_timerAnim;

public:
	AnimationMapped(sf::Sprite *spriteTarget, double firstTime);

	virtual void restart() = 0;
	virtual void setTexture(int indexLine) = 0;
	virtual void setActualTexture() = 0;
	
	virtual bool actualize(double time);
};