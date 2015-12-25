#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "PersonalAnimationManager.hpp"
#include "RotationTransformation.hpp"
#include "TranslationTransformation.hpp"

// UNCHECKED : ROTATION

class DrawableObject
{
private:
	PersonalAnimationManager m_personalAnimationManager;
	RotationTransformation m_rotationManager;
	TranslationTransformation m_translationManager;

	sf::Sprite* getSprite();

public:
	DrawableObject(std::vector <AnimationPerFrame*> animations);

	sf::Vector2f getPosition() const;

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f & position);
	void setOriginCenter();

	void startRotationWithTime(float speedPerSecond, double time);
	void startRotationWithAngle(float speedPerSecond, float angle);
	void setInfiniteRotation(bool state);
	void startTranslationWithSpeed(double time, sf::Vector2f const& speedPerSecond);
	void startTranslationWithTargetPoint(double time, sf::Vector2f const& targetPoint);
	void startTextureRectAnimation();

	void actualize(double time);
	void draw(sf::RenderWindow* window);
	void startAnimation();
	void stopAnimation();
	void restartAnimation();
	void setRepeatAnimation(bool state);
};