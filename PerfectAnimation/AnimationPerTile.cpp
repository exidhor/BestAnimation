#include "AnimationPerTile.hpp"

AnimationPerTile::AnimationPerTile(sf::Sprite* spriteTarget, Tile* tile)
	:AnimationMapped(spriteTarget),
	m_timerAnim(getActualTime())
{
	m_tile = tile;
	m_spriteTarget->setTexture(*m_tile->getTextureTile());
	setActualTexture();
}

void AnimationPerTile::restart()
{
	m_indexCurrentTextureRect.y = 0;
	m_timerAnim.restart(getActualTime());
	setActualTexture();
}

void AnimationPerTile::setTexture(int indexLine)
{
	m_indexCurrentTextureRect.y = indexLine;
	restart();
}

void AnimationPerTile::setActualTexture()
{
	m_spriteTarget->setTextureRect(m_tile->getTextureRect(m_indexCurrentTextureRect));
}

double AnimationPerTile::getTime(sf::Vector2i const& coord)
{
	return m_tile->getTime()[coord.y][coord.x];
}

double AnimationPerTile::getActualTime()
{
	return getTime(m_indexCurrentTextureRect);
}

bool AnimationPerFrame::increaseIndice()
{
	m_indiceCurrentTexture++;
	if (m_indiceCurrentTexture >= m_frames.size())
	{
		restart();
		return true;
	}
	m_timerAnim.setTime(m_frames[m_indiceCurrentTexture]->getTimeDisplay());
	return false;
}