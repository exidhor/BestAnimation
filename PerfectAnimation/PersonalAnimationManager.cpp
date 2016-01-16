#include "PersonalAnimationManager.hpp"

PersonalAnimationManager::PersonalAnimationManager(Animation* animation)
	:m_timeAnim(0)
{
	m_animation = animation;
	m_animation->setTargetSprite(&m_sprite);
	synchroTimeAnimWithFrame();

	m_isStarted = false;
	m_isRepeated = false;
}

void PersonalAnimationManager::restart()
{
	m_animation->restart();
	m_timeAnim.restart();
}

void PersonalAnimationManager::softRestart()
{
	m_animation->restart();
	m_timeAnim.softRestart();
}

void PersonalAnimationManager::actualize(double timeSpent)
{
	if (m_isStarted)
	{
		if (m_timeAnim.removeTime(timeSpent))
		{
			if (m_animation->increaseIndice())
			{
				if (m_isRepeated)
				{
					softRestart();
				}
				else
				{
					restart();
					m_isStarted = false;
				}
				
			}
			m_timeAnim.softRestart();
		}
	}
}

void PersonalAnimationManager::start()
{
	m_isStarted = true;
}

void PersonalAnimationManager::stop()
{
	m_isStarted = false;
}

void PersonalAnimationManager::drawSprite(sf::RenderWindow* ptr_window)
{
	ptr_window->draw(m_sprite);
}

void PersonalAnimationManager::setStateAnimation(int key)
{
	m_animation->setStateAnimation(key);
	restart();
}

void PersonalAnimationManager::setIsRepeated(bool state)
{
	m_isRepeated = state;
}

void PersonalAnimationManager::setPositionSprite(sf::Vector2f const& position)
{
	m_sprite.setPosition(position);
}

void PersonalAnimationManager::setPositionSprite(float abs, float ord)
{
	m_sprite.setPosition(abs, ord);
}

sf::Vector2f PersonalAnimationManager::getPositionSprite()
{
	return m_sprite.getPosition();
}

sf::Sprite* PersonalAnimationManager::getSprite()
{
	return &m_sprite;
}

void PersonalAnimationManager::synchroTimeAnimWithFrame()
{
	m_timeAnim.setTime(m_animation->getActualTimeFrame());
}