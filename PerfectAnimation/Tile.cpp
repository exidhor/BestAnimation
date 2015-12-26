#include "Tile.hpp"

Tile::Tile(unsigned int numberFramePerLine, unsigned int numberFramePerCulumn,
	sf::Texture* tile, std::vector <std::vector <double> > timeDisplay)
{
	m_tile = tile;
	m_timeDisplay = timeDisplay;
	m_sizeOfOneTexture.x = m_tile->getSize().x / numberFramePerLine;
	m_sizeOfOneTexture.y = m_tile->getSize().y / numberFramePerCulumn;
}

bool Tile::goToTheNextFrame()
{
	m_indexCurrentTextureRect.x++;
	if (m_indexCurrentTextureRect.x >= m_timeDisplay[m_indexCurrentTextureRect.y].size())
	{
		m_indexCurrentTextureRect.x = 0;
		return true;
	}
	return false;
}

void Tile::goToTheLine(unsigned int indexCulumn)
{
	m_indexCurrentTextureRect.y = indexCulumn;
}