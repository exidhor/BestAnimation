#include "LinearTransformation.hpp"

LinearTransformation::LinearTransformation(sf::Sprite* targetSprite)
	:Transformation(targetSprite),
	m_time(0)
{
	m_speedOrd = 0;
	m_isDeterminedByTime = false;
}

bool LinearTransformation::actualize(double time)
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

			if (m_speedAbs >= 0 && m_spriteTarget->getPosition().x >= m_targetPoint.x)
			{
				XisArrived = true;
			}
			else if (m_speedAbs <= 0 && m_spriteTarget->getPosition().x <= m_targetPoint.x)
			{
				XisArrived = true;
			}

			if (m_speedOrd >= 0 && m_spriteTarget->getPosition().y >= m_targetPoint.y)
			{
				YisArrived = true;
			}
			else if (m_speedOrd <= 0 && m_spriteTarget->getPosition().y <= m_targetPoint.y)
			{
				YisArrived = true;
			}

			if (XisArrived && YisArrived && !m_isInfinite)
			{
				placeSpriteToTheEndOfTransformation();
				m_isOn = false;
				isFinish = true;
			}
		}
		doTheTransformation(deplacement);
		return isFinish;
	}

	return false;
}

void LinearTransformation::initByTargetPoint(double time, sf::Vector2f const& targetPoint)
{
	m_isDeterminedByTime = false;
	m_targetPoint = targetPoint;
	m_speedAbs = (m_targetPoint.x - getPositionForTransformation().x) / time;
	m_speedOrd = (m_targetPoint.y - getPositionForTransformation().y) / time;
}

void LinearTransformation::initBySpeed(double time, sf::Vector2f const& speedPerSecond)
{
	m_isDeterminedByTime = true;
	m_speedAbs = speedPerSecond.x;
	m_speedOrd = speedPerSecond.y;
	m_time.setTime(time);
}

sf::Vector2f LinearTransformation::getPositionForTransformation()
{
	return m_spriteTarget->getPosition();
}

void LinearTransformation::placeSpriteToTheEndOfTransformation()
{
	// VOID : define into the children
}

void LinearTransformation::doTheTransformation(sf::Vector2f const& deplacement)
{
	// VOID : define into the children
}