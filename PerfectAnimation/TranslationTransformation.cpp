#include "TranslationTransformation.hpp"

TranslationTransformation::TranslationTransformation(sf::Sprite* spriteTraget)
	:Transformation(spriteTraget)
{
	m_endDeterminedByDeplacement = false;
	m_speedOrd = 0;
}

void TranslationTransformation::initTranslationByTime(sf::Vector2f const& targetPoint, double time)
{
	m_endDeterminedByDeplacement = false;
	m_time.setTime(time);
	//m_speedAbs = speedPerSecond.x;
	//m_speedOrd = speedPerSecond.y;
}

void TranslationTransformation::initTranslationByDeplacement(sf::Vector2f const& speedPerSecond, sf::Vector2f const& targetPoint)
{
	m_endDeterminedByDeplacement = true;
	m_targetPoint = targetPoint;
	m_speedAbs = speedPerSecond.x;
	m_speedOrd = speedPerSecond.y;
}

bool TranslationTransformation::actualize(double time)
{
	if (m_isOn)
	{
		bool isFinish = false;
		sf::Vector2f deplacement(m_speedAbs*(float)time, m_speedOrd*(float)time);
		if (m_endDeterminedByDeplacement)
		{

		}
		else
		{

		}
	}

	return false;
}