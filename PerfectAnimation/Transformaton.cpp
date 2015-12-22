#include "Transformation.hpp"

Transformation::Transformation(sf::Sprite* spriteTarget)
{
	m_spriteTarget = spriteTarget;
	m_speedAbs = 0;
	m_isInfinite = false;
	m_isOn = false;
}

void Transformation::start()
{
	m_isOn = true;
}

void Transformation::stop()
{
	m_isOn = false;
}

void Transformation::setIsInfinite(bool state)
{
	m_isInfinite = state;
}

void Transformation::setSpeed(float speed)
{
	m_speedAbs = speed;
}