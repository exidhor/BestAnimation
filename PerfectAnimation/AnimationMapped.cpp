#include "AnimationMapped.hpp"

AnimationMapped::AnimationMapped(sf::Sprite* spriteTarget, double firstTime)
	:m_timerAnim(firstTime)
{
	m_spriteTarget = spriteTarget;
}

TokenActualizationSituation AnimationMapped::actualize(double time)
{
	// TODO
	if (m_timerAnim.removeTime(time))
	{
		return TokenActualizationSituation(true, increaseIndice());
	}
	return TokenActualizationSituation(false, false);
}