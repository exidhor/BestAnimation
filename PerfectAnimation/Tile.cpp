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

void Tile::goToTheLine(unsigned int indexLine)
{
	m_indexCurrentTextureRect.x = 0;
	m_indexCurrentTextureRect.y = indexLine;
}

sf::Texture* Tile::getTextureTile()
{
	return m_tile;
}

sf::IntRect Tile::getTextureRect()
{
	return sf::IntRect(
		m_indexCurrentTextureRect.x * m_sizeOfOneTexture.x,
		m_indexCurrentTextureRect.y * m_sizeOfOneTexture.y,
		m_sizeOfOneTexture.x,
		m_sizeOfOneTexture.y
		);
}

sf::IntRect Tile::getTextureRect(sf::Vector2i coord)
{
	return sf::IntRect(
		coord.x * m_sizeOfOneTexture.x,
		coord.y * m_sizeOfOneTexture.y,
		m_sizeOfOneTexture.x,
		m_sizeOfOneTexture.y
		);
}

std::vector <std::vector <double> > Tile::getTime()
{
	return m_timeDisplay;
}