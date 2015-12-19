#include "Frame.hpp"

Frame::Frame(sf::Texture* ptr_texture, double timeDisplay)
{
	m_texture = ptr_texture;
	m_timeDispay = timeDisplay;
}

sf::Texture* Frame::getTexturePtr()
{
	return m_texture;
}

double Frame::getTimeDisplay()
{
	return m_timeDispay;
}