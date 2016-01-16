#include "PersonalAnimationManager.hpp"

PersonalAnimationManager::PersonalAnimationManager()
{
	//void
}

sf::Sprite* PersonalAnimationManager::getSprite()
{
	return &m_sprite;
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
	m_isStarted = true;
	// TO DO : restart temps + texture
}

void PersonalAnimationManager::draw(sf::RenderWindow* ptr_window)
{
	ptr_window->draw(m_sprite);
}

void PersonalAnimationManager::setIsRepeated(bool state)
{
	m_isRepeated = state;
}

void PersonalAnimationManager::setPosition(sf::Vector2f const& position)
{
	m_sprite.setPosition(position);
}

void PersonalAnimationManager::setPosition(float abs, float ord)
{
	m_sprite.setPosition(abs, ord);
}

sf::Vector2f PersonalAnimationManager::getPosition()
{
	return m_sprite.getPosition();
}