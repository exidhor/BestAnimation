#include "TextureContainer.hpp"

TextureContainer::TextureContainer(double timePerFrame)
{
	m_timePerFrame = timePerFrame;
}

double TextureContainer::getTimePerFrame()
{
	return m_timePerFrame;
}