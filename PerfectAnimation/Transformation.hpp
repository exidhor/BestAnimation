#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "TimeAnim.hpp"

/**
Represente une animation generique (translation, rotation, translationTexture)
*/
class Transformation
{
protected:
	bool m_isOn;
	bool m_isInfinite;
	float m_speedAbs;
	sf::Sprite* m_spriteTarget;
public:
	Transformation(sf::Sprite* spriteTarget);

	virtual void start();
	virtual bool actualize(double time) = 0;

	void stop();

	void setIsInfinite(bool state);
	void setSpeed(float speed);
};