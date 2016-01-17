#include "AnimationPerTile.hpp"

AnimationPerTile::AnimationPerTile(Tile* tile)
	: AnimationPerTile(NULL, tile)
{
	//void
}

AnimationPerTile::AnimationPerTile(sf::Sprite* targetSprite, Tile* tile)
	: Animation(targetSprite)
{
	m_tile = tile;
}

AnimationPerTile::AnimationPerTile(sf::Texture* tile, double timePerFrame, sf::Vector2i numberOfTextures)
	: AnimationPerTile(NULL, new Tile(tile, timePerFrame, numberOfTextures))
{
	//void
}

void AnimationPerTile::setActualTexture()
{
	m_targetSprite->setTextureRect(getCurrentTextureRect());
}

unsigned int AnimationPerTile::getSizeCurrentLine()
{
	return m_tile->getNumberOfTexures().y;
}

sf::IntRect AnimationPerTile::getCurrentTextureRect()
{
	return sf::IntRect(
		m_currentIndex.x * m_tile->getSizeOfOneTexture().x,
		m_currentIndex.y * m_tile->getSizeOfOneTexture().y,
		m_tile->getSizeOfOneTexture().x,
		m_tile->getSizeOfOneTexture().y);
}

double AnimationPerTile::getActualTimeFrame()
{
	return m_tile->getTimePerFrame();
}