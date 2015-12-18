#include "DrawableObject.hpp"

DrawableObject::DrawableObject(std::vector <Animation*> animations)
	:m_personalAnimationManager(animations)
{

}

sf::Vector2f DrawableObject::getPosition() const
{
	return m_personalAnimationManager.getPosition();
}

void DrawableObject::setPosition(float x, float y)
{
	m_personalAnimationManager.setPosition(x, y);
}

void DrawableObject::setPosition(sf::Vector2f & position)
{
	m_personalAnimationManager.setPosition(position);
}

void DrawableObject::startRotation(double time, float speedPerSecond)
{

}

void DrawableObject::startTranslation(double time, float speed)
{

}

void DrawableObject::draw(sf::RenderWindow* window)
{
	m_personalAnimationManager.draw(window);
}


void DrawableObject::actualize(double time)
{
	m_personalAnimationManager
}