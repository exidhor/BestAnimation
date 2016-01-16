#include "Animation.hpp"

Animation::Animation()
{
	m_targetSprite = NULL;
}

Animation::Animation(sf::Sprite* targetSprite)
{
	m_targetSprite = targetSprite;
}

bool Animation::increaseIndice()
{
	m_currentIndex.y++;
	if (m_currentIndex.y >= getSizeCurrentLine())
	{
		restart();
		return true;
	}
	setActualTexture();
	return false;
}

void Animation::restart()
{
	m_currentIndex.y = 0;
	setActualTexture();
}

void Animation::setStateAnimation(int indexLine)
{
	m_currentIndex.x = indexLine;
	restart();
}

void Animation::setTargetSprite(sf::Sprite* targetSprite)
{
	m_targetSprite = targetSprite;

}