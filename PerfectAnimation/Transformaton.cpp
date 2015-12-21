#include "Transformation.hpp"

Transformation::Transformation(sf::Sprite* spriteTarget)
	:m_time(0)
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

void Transformation::setTime(double time)
{
	m_time.setTime(time);
}

void Transformation::setSpeed(float speed)
{
	m_speedAbs = speed;
}

void Transformation::restart()
{
	m_time.restart(m_time.getTimeDisplay());
}