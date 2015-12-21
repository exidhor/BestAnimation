#include "RotationTransformation.hpp"

RotationTransformation::RotationTransformation(sf::Sprite* spriteTarget)
	:Transformation(spriteTarget)
{
	m_finalAngle = 0;
	m_endDeterminedByAngle = false;
}

void RotationTransformation::initRotateByTime(float speed, double time)
{
	m_endDeterminedByAngle = false;
	m_time.setTime(time);
	m_speedAbs = speed;
}

void RotationTransformation::initRotateByAngle(float speed, float finalAngle)
{
	m_endDeterminedByAngle = true;
	m_finalAngle = finalAngle;
	m_angleDegreeLeft = finalAngle;
	m_speedAbs = speed;
}

bool RotationTransformation::actualize(double time)
{
	if (m_isOn)
	{
		bool isFinish = false;
		float angleRotation = m_speedAbs * time;

		if (m_endDeterminedByAngle)
		{
			m_angleDegreeLeft -= angleRotation;
			if (m_angleDegreeLeft < 0 && m_speedAbs > 0)
			{
				if (m_isInfinite)
				{
					m_angleDegreeLeft += m_finalAngle;
				}
				else
				{
					angleRotation += m_angleDegreeLeft;
					isFinish = true;
					m_isOn = false;
				}
			}
			else if (m_angleDegreeLeft >= m_finalAngle && m_speedAbs < 0)
			{
				if (m_isInfinite)
				{
					m_angleDegreeLeft -= m_finalAngle;
				}
				else
				{
					angleRotation -= m_angleDegreeLeft;
					isFinish = true;
					m_isOn = false;
				}
			}
		}

		else
		{
			if (m_time.removeTime(time))
			{
				if (!m_isInfinite)
				{
					angleRotation = m_speedAbs * (time - m_time.getTimeLeft());
					isFinish = true;
					m_isOn = false;
				}
				else
				{
					m_time.softRestart();
				}
			}
		}

		m_spriteTarget->rotate(angleRotation);
		
		return isFinish;
	}

	return false;
}
