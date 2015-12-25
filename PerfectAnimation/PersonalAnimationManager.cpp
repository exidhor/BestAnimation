#include "PersonalAnimationManager.hpp"

PersonalAnimationManager::PersonalAnimationManager(std::vector <AnimationPerFrame*> animations)
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

void PersonalAnimationManager::setIsRepeated(bool state)
{
	m_isRepeated = state;
}

void PersonalAnimationManager::start()
{
	m_isStarted = true;
}

void PersonalAnimationManager::stop()
{
	m_isStarted = false;
}

void PersonalAnimationManager::restart()
{
	m_animations[m_currentKey]->restart();
}

void PersonalAnimationManager::draw(sf::RenderWindow* ptr_window)
{
	ptr_window->draw(m_sprite);
}

void PersonalAnimationManager::setStateAnimation(int key)
{
	m_currentKey = key;
	m_sprite.setTexture(*getCurrentTexture());
}

sf::Texture* PersonalAnimationManager::getCurrentTexture()
{
	return m_animations[m_currentKey]->getActualTexture();
}

void PersonalAnimationManager::setPosition(sf::Vector2f const& position)
{
	m_sprite.setPosition(position);
}

void PersonalAnimationManager::setPosition(float abs, float ord)
{
	m_sprite.setPosition(abs, ord);
}

sf::Vector2f PersonalAnimationManager::getPosition() const
{
	return m_sprite.getPosition();
}

sf::Sprite* PersonalAnimationManager::getSprite()
{
	return &m_sprite;
}

void PersonalAnimationManager::actualize(double time)
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