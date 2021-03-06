#include "DrawableObject.hpp"

DrawableObject::DrawableObject(Animation *animation)
	:m_personalAnimationManager(animation),
	m_rotationManager(getSprite()),
	m_translationManager(getSprite())
{
	setOriginCenter();
}

sf::Vector2f DrawableObject::getPosition()
{
	return m_personalAnimationManager.getPositionSprite();
}

void DrawableObject::setPosition(float x, float y)
{
	m_personalAnimationManager.setPositionSprite(x, y);
}

void DrawableObject::setPosition(sf::Vector2f & position)
{
	m_personalAnimationManager.setPositionSprite(position);
}

void DrawableObject::startRotationWithTime(float speedPerSecond, double time)
{
	m_rotationManager.initRotateByTime(speedPerSecond, time);
	m_rotationManager.start();
}

void DrawableObject::startRotationWithAngle(float speedPerSecond, float angle)
{
	m_rotationManager.initRotateByAngle(speedPerSecond, angle);
	m_rotationManager.start();
}

void DrawableObject::startTranslationWithSpeed(double time, sf::Vector2f const& speedPerSecond)
{
	m_translationManager.initBySpeed(time, speedPerSecond);
	m_translationManager.start();
}

void DrawableObject::startTranslationWithTargetPoint(double time, sf::Vector2f const& targetPoint)
{
	m_translationManager.initByTargetPoint(time, targetPoint);
	m_translationManager.start();
}

void DrawableObject::draw(sf::RenderWindow* window)
{
	m_personalAnimationManager.drawSprite(window);
}


void DrawableObject::actualize(double time)
{
	m_personalAnimationManager.actualize(time);
	m_rotationManager.actualize(time);
	m_translationManager.actualize(time);
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