#include "TranslationTransformation.hpp"

TranslationTransformation::TranslationTransformation(sf::Sprite* spriteTraget)
	:Transformation(spriteTraget)
{
	m_speedOrd = 0;
}

void TranslationTransformation::initTranslationByTargetPoint(double time, sf::Vector2f const& targetPoint)
{
	m_targetPoint = targetPoint;

	m_speedAbs = (m_targetPoint.x - m_spriteTarget->getPosition().x) / time;
	m_speedOrd = (m_targetPoint.y - m_spriteTarget->getPosition().y) / time;
}

void TranslationTransformation::initTranslationBySpeed(double time, sf::Vector2f const& speedPerSecond)
{
	m_speedAbs = speedPerSecond.x;
	m_speedOrd = speedPerSecond.y;

	m_targetPoint = sf::Vector2f(m_speedAbs*time + m_spriteTarget->getPosition().x,
		m_speedOrd*time + m_spriteTarget->getPosition().y);
}

bool TranslationTransformation::actualize(double time)
{
	if (m_isOn)
	{
		bool XisArrived = false;
		bool YisArrived = false;
		sf::Vector2f deplacement(m_speedAbs*(float)time, m_speedOrd*(float)time);

		if (m_speedAbs > 0 && m_spriteTarget->getPosition().x >= m_targetPoint.x)
		{
			XisArrived = true;
		}
		else if (m_speedAbs < 0 && m_spriteTarget->getPosition().x <= m_targetPoint.x)
		{
			XisArrived = true;
		}
		
		if (m_speedOrd > 0 && m_spriteTarget->getPosition().y >= m_targetPoint.y)
		{
			YisArrived = true;
		}
		else if (m_speedOrd < 0 && m_spriteTarget->getPosition().y <= m_targetPoint.y)
		{
			YisArrived = true;
		}

		if (XisArrived && YisArrived && !m_isInfinite)
		{
			m_spriteTarget->setPosition(m_targetPoint);
			return true;
		}

		m_spriteTarget->move(deplacement);
	}

	return false;
}