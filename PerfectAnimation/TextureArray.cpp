#include "TextureArray.hpp"


TextureArray::TextureArray(std::vector <std::vector <sf::Texture*> > textureArray, double timePerFrame)
	:TextureContainer(timePerFrame)
{
	m_textureArray = textureArray;
}

sf::Texture* TextureArray::getPtrTexture(int x, int y)
{
	return m_textureArray[x][y];
}

unsigned int TextureArray::getSize(int x)
{
	return m_textureArray[x].size();
}