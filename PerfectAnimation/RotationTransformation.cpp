#include "RotationTransformation.hpp"

RotationTransformation::RotationTransformation(sf::Sprite* spriteTarget)
	:Transformation(spriteTarget)
{
	m_finalAngle = 0;
}


void RotationTransformation::initRotateByTime(float speed, double time)
{
	m_finalAngle =(float)(speed * time);
	m_speedAbs = speed;
}

void RotationTransformation::initRotateByAngle(float speed, float finalAngle)
{
	m_finalAngle = finalAngle;
	m_angleDegreeLeft = finalAngle;
	m_speedAbs = speed;
}

bool RotationTransformation::actualize(double time)
{
	if (m_isOn)
	{
		bool isFinish = false;
		float angleRotation = m_speedAbs * (float)time;

		m_angleDegreeLeft -= angleRotation;
		if (m_angleDegreeLeft < 0 && m_speedAbs > 0)
		{
			isFinish = endOfRotation(angleRotation, true);
		}
		else if (m_angleDegreeLeft >= 2*m_finalAngle && m_speedAbs < 0)
		{
			isFinish = endOfRotation(angleRotation, false);
		}
		m_spriteTarget->rotate(angleRotation);
		
		return isFinish;
	}

	return false;
}

bool RotationTransformation::endOfRotation(float & angleRotation, bool speedUpperThanZero)
{
	if (m_isInfinite)
	{
		if (speedUpperThanZero)
		{
			m_angleDegreeLeft += m_finalAngle;
		}
		else
		{
			m_angleDegreeLeft -= m_finalAngle;
		}
		return false;
	}

	angleRotation -= m_angleDegreeLeft;
	m_isOn = false;
	
	return true;
}
