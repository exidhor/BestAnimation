#include "TranslationTransformation.hpp"

TranslationTransformation::TranslationTransformation(sf::Sprite* spriteTraget)
	:Transformation(spriteTraget),
	m_time(0)
{
	m_speedOrd = 0;
	m_isDeterminedByTime = false;
}

void TranslationTransformation::initTranslationByTargetPoint(double time, sf::Vector2f const& targetPoint)
{
	m_isDeterminedByTime = false;
	m_targetPoint = targetPoint;
	m_speedAbs = (m_targetPoint.x - m_spriteTarget->getPosition().x) / time;
	m_speedOrd = (m_targetPoint.y - m_spriteTarget->getPosition().y) / time;
}

void TranslationTransformation::initTranslationBySpeed(double time, sf::Vector2f const& speedPerSecond)
{
	m_isDeterminedByTime = true;
	m_speedAbs = speedPerSecond.x;
	m_speedOrd = speedPerSecond.y;
	m_time.setTime(time);
}

bool TranslationTransformation::actualize(double time)
{
	if (m_isOn)
	{
		bool isFinish = false;
		sf::Vector2f deplacement;
		if (m_isDeterminedByTime)
		{
			if (m_time.removeTime(time))
			{
				time += m_time.getTimeLeft();
				m_isOn = false;
				isFinish = true;
			}
			deplacement.x = m_speedAbs*time;
			deplacement.y = m_speedOrd*time;
		}
		else
		{
			bool XisArrived = false;
			bool YisArrived = false;
			deplacement.x = m_speedAbs*(float)time;
			deplacement.y = m_speedOrd*(float)time;

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
				m_isOn = false;
				isFinish = true;
			}	
		}
		m_spriteTarget->move(deplacement);
		return isFinish;
	}

	return false;
}