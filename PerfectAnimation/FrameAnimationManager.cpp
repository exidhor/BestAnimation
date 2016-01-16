#include "FrameAnimationManager.hpp"

FrameAnimationManager::FrameAnimationManager(std::vector <AnimationPerFrame*> animations)
{
	if (animations.size() == 0)
	{
		std::cerr << "Error, size of animations vector is 0" << std::endl;
	}
	m_animations = animations;
	m_isStarted = false;
	m_isRepeated = false;
	m_currentKey = 0;
	m_sprite.setTexture(*getCurrentTexture());
}

void FrameAnimationManager::setIsRepeated(bool state)
{
	m_isRepeated = state;
}

void FrameAnimationManager::start()
{
	m_isStarted = true;
}

void FrameAnimationManager::stop()
{
	m_isStarted = false;
}

void FrameAnimationManager::restart()
{
	m_animations[m_currentKey]->restart();
}

void FrameAnimationManager::draw(sf::RenderWindow* ptr_window)
{
	ptr_window->draw(m_sprite);
}

void FrameAnimationManager::setStateAnimation(int key)
{
	m_currentKey = key;
	m_sprite.setTexture(*getCurrentTexture());
}

sf::Texture* FrameAnimationManager::getCurrentTexture()
{
	return m_animations[m_currentKey]->getActualTexture();
}

void FrameAnimationManager::setPosition(sf::Vector2f const& position)
{
	m_sprite.setPosition(position);
}

void FrameAnimationManager::setPosition(float abs, float ord)
{
	m_sprite.setPosition(abs, ord);
}

sf::Vector2f FrameAnimationManager::getPosition() const
{
	return m_sprite.getPosition();
}

sf::Sprite* FrameAnimationManager::getSprite()
{
	return &m_sprite;
}

void FrameAnimationManager::actualize(double time)
{
	if (m_isStarted)
	{
		TokenActualizationSituation actualizationSituation = m_animations[m_currentKey]->actualize(time);
		if (actualizationSituation.isNewFrame)
		{
			m_sprite.setTexture(*getCurrentTexture());
		}

		if (actualizationSituation.isFinish)
		{
			if (!m_isRepeated)
			{
				m_isStarted = false;
			}
		}
	}
}