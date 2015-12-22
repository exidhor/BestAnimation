#include "RotationTransformation.hpp"

RotationTransformation::RotationTransformation(sf::Sprite* spriteTarget)
	:Transformation(spriteTarget)
{
	m_finalAngle = 0;
	m_angleDegreeAdvancement = 0;
}


void RotationTransformation::initRotateByTime(float speed, double time)
{
	m_finalAngle =(float)(speed * time);
	m_speedAbs = speed;
}

void RotationTransformation::initRotateByAngle(float speed, float finalAngle)
{
	if (finalAngle < 0)
	{
		int endRotation = - (int)finalAngle % 360;
		float floatPart = finalAngle - (int)finalAngle;
		int nbOfTurn = finalAngle / -360;
		finalAngle = nbOfTurn * 360 + endRotation + floatPart;
	}
	m_finalAngle = finalAngle;
	m_angleDegreeAdvancement = 0;
	m_speedAbs = speed;
}

bool RotationTransformation::actualize(double time)
{
	if (m_isOn)
	{
		bool isFinish = false;
		float angleRotation = m_speedAbs * (float)time;

		m_angleDegreeAdvancement += angleRotation;
		if (m_speedAbs > 0 && m_angleDegreeAdvancement >= m_finalAngle)
		{
			isFinish = endOfRotation(angleRotation, true);
		}
		else if (m_speedAbs < 0 && m_angleDegreeAdvancement <= -m_finalAngle)
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
			m_angleDegreeAdvancement -= m_finalAngle;
		}
		else
		{
			m_angleDegreeAdvancement += m_finalAngle;
		}
		return false;
	}

	if (speedUpperThanZero)
	{
		angleRotation -= m_angleDegreeAdvancement - m_finalAngle;
	}
	else
	{
		angleRotation -= m_finalAngle - m_angleDegreeAdvancement;
	}
	m_isOn = false;
	
	return true;
}
