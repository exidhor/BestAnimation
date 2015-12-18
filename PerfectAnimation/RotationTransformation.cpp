#include "RotationTransformation.hpp"

RotationTransformation::RotationTransformation()
	:Transformation()
{
	m_finalAngle = 0;
	m_endDeterminedByAngle = false;
}

void RotationTransformation::rotateByTime(float speed, double time)
{
	m_endDeterminedByAngle = false;
	m_time.setTime(time);
}

void RotationTransformation::rotateByAngle(float speed, float finalAngle)
{
	m_endDeterminedByAngle = true;
	m_finalAngle = finalAngle;
}

bool RotationTransformation::actualize(double time)
{
	return true;
}
