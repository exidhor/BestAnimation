#include "AnimationPerFrame.hpp"

/**
Cree un animation a partir d'un tableau de textures
*/
AnimationPerFrame::AnimationPerFrame(std::vector<Frame*> v_ptr_frames)
	:m_timerAnim(v_ptr_frames[0]->getTimeDisplay())
{
	if (v_ptr_frames.size() <= 0)
	{
		std::cerr << "Error, size of textures vector is 0" << std::endl;
	}
	m_indiceCurrentTexture = 0;
	m_frames = v_ptr_frames;
}

void AnimationPerFrame::restart()
{
	m_indiceCurrentTexture = 0;
	m_timerAnim.restart(m_frames[0]->getTimeDisplay());
}

TokenActualizationSituation AnimationPerFrame::actualize(double time)
{
	if (m_timerAnim.removeTime(time))
	{
		return TokenActualizationSituation(true, increaseIndice());
	}
	return TokenActualizationSituation(false, false);
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

sf::Texture* AnimationPerFrame::getActualTexture()
{
	return m_frames[m_indiceCurrentTexture]->getTexturePtr();
}