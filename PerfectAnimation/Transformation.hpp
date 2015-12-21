#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <map>
#include <vector>
#include "TimeAnim.hpp"

/**
Represente une animation generique (translation, rotation, translationTexture)
*/
class Transformation
{
protected:
	bool m_isOn;
	bool m_isInfinite;
	TimeAnim m_time;
	float m_speedAbs;
	sf::Sprite* m_spriteTarget;
public:
	Transformation(sf::Sprite* spriteTarget);
	void start();
	void stop();
	void restart();

	void setIsInfinite(bool state);
	void setTime(double time);
	void setSpeed(float speed);
	
	virtual bool actualize(double time) = 0;
};