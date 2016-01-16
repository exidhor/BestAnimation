#include "AnimationPerTextureArray.hpp"

AnimationPerTextureArray::AnimationPerTextureArray(TextureArray* textureArray)
	:AnimationPerTextureArray(NULL, textureArray)
{
	//void
}

AnimationPerTextureArray::AnimationPerTextureArray(sf::Sprite* targetSprite, TextureArray* textureArray)
	:Animation(targetSprite)
{
	m_textureArray = textureArray;
}

void AnimationPerTextureArray::setActualTexture()
{
	m_targetSprite->setTexture(*(m_textureArray->getPtrTexture(m_currentIndex.x, m_currentIndex.y)));
}

unsigned int AnimationPerTextureArray::getSizeCurrentLine()
{
	return m_textureArray->getSize(m_currentIndex.x);
}

double AnimationPerTextureArray::getActualTimeFrame()
{
	return m_textureArray->getTimePerFrame();
}