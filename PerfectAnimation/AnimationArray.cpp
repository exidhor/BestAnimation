#include "AnimationArray.hpp"

AnimationArray::AnimationArray(sf::Sprite* spriteTarget, std::vector<AnimationPerFrame*> animationArray)
	:AnimationMapped(spriteTarget)
{
	m_animationArray = animationArray;
	setActualTexture();
}

void AnimationArray::restart()
{
	m_indexLine = 0;
	m_animationArray[m_indexLine]->restart();
	setActualTexture();
}

void AnimationArray::setTexture(int indexLine)
{
	m_indexLine = indexLine;
	restart();
}

bool AnimationArray::actualize(double time)
{
	TokenActualizationSituation tokenActualizationSituation = m_animationArray[m_indexLine]->actualize(time);
	
	if (tokenActualizationSituation.isFinish)
	{
		if (!m_isRepeated)
		{
			m_isStarted = false;
		}
	}
	if (tokenActualizationSituation.isNewFrame)
	{
		m_sprite->setTexture(*getCurrentTexture());
	}
}

void AnimationArray::setActualTexture()
{
	m_spriteTarget->setTexture(*m_animationArray[m_indexLine]->getActualTexture());
}