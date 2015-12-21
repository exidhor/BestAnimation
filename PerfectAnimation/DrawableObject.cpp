#include "DrawableObject.hpp"

DrawableObject::DrawableObject(std::vector <Animation*> animations)
	:m_personalAnimationManager(animations),
	m_rotationManager(getSprite())
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

void DrawableObject::startRotationWithTime(float speedPerSecond, double time)
{
	//m_rotationManager.initRotateByTime(speedPerSecond, time);
	m_rotationManager.start();
}

void DrawableObject::startRotationWithAngle(float angle, double time)
{
	m_rotationManager.initRotateByAngle(angle, time);
	m_rotationManager.start();
}

void DrawableObject::startTranslation(float speed, double time)
{
	// TO DO
}

void DrawableObject::draw(sf::RenderWindow* window)
{
	m_personalAnimationManager.draw(window);
}


void DrawableObject::actualize(double time)
{
	m_personalAnimationManager.actualize(time);
	m_rotationManager.actualize(time);
}

void DrawableObject::startAnimation()
{
	m_personalAnimationManager.start();
}

void DrawableObject::stopAnimation()
{
	m_personalAnimationManager.stop();
}

void DrawableObject::restartAnimation()
{
	m_personalAnimationManager.restart();
}

void DrawableObject::setRepeatAnimation(bool state)
{
	m_personalAnimationManager.setIsRepeated(state);
}

void DrawableObject::setOriginCenter()
{
	getSprite()->setOrigin(getSprite()->getOrigin().x + getSprite()->getGlobalBounds().width / 2,
		getSprite()->getOrigin().y + getSprite()->getGlobalBounds().height / 2);
}

sf::Sprite* DrawableObject::getSprite()
{
	return m_personalAnimationManager.getSprite();
}

void DrawableObject::setInfiniteRotation(bool state)
{
	m_rotationManager.setIsInfinite(state);
}