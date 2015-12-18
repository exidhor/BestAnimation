#include "Animation.hpp"

/**
Cree un animation a partir d'un tableau de textures
*/
Animation::Animation(std::vector<Frame*> v_ptr_frames, double fullTimeDisplay)
	:m_timerAnim(fullTimeDisplay)
{
	if (v_ptr_frames.size() <= 0)
	{
		std::cerr << "Error, size of textures vector is 0" << std::endl;
	}
	m_indiceCurrentTexture = 0;
	m_frames = v_ptr_frames;
}

void Animation::restart()
{
	m_indiceCurrentTexture = 0;
	m_timerAnim.restart();
}

bool Animation::actualize(double time)
{
	if (m_timerAnim.removeTime(time))
	{
		return increaseIndice();
	}
	return false;
}

bool Animation::increaseIndice()
{
	m_indiceCurrentTexture++;
	if (m_indiceCurrentTexture >= m_frames.size())
	{
		m_indiceCurrentTexture = 0;
		return true;
	}
	return false;
}

sf::Texture* Animation::getActualTexture()
{
	return m_frames[m_indiceCurrentTexture]->getTexturePtr();
}