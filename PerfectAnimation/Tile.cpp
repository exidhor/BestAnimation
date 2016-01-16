#include "Tile.hpp"

Tile::Tile(sf::Texture* tile, double timePerFrame, sf::Vector2i numberOfTextures)
	:TextureContainer(timePerFrame)
{
	m_tile = tile;
	m_numberOfTextures = numberOfTextures;
	m_sizeOfOneTexture.x = tile->getSize().x / m_numberOfTextures.x;
	m_sizeOfOneTexture.y = tile->getSize().y / m_numberOfTextures.y;
}

sf::Vector2f Tile::getSizeOfOneTexture()
{
	return m_sizeOfOneTexture;
}

sf::Texture* Tile::getPtrTexture()
{
	return m_tile;
}

sf::Vector2i Tile::getNumberOfTexures()
{
	return m_numberOfTextures;
}