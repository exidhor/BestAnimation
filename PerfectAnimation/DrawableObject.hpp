#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <map>
#include <vector>
#include "PersonalAnimationManager.hpp"
#include "RotationTransformation.hpp"

// UNCHECKED : ROTATION

class DrawableObject
{
private:
	PersonalAnimationManager m_personalAnimationManager;
	RotationTransformation m_rotationManager;

	sf::Sprite* getSprite();

public:
	DrawableObject(std::vector <Animation*> animations);

	sf::Vector2f getPosition() const;

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f & position);
	void setOriginCenter();

	void startRotationWithTime(float speedPerSecond, double time);
	void startRotationWithAngle(float angle, double time);
	void setInfiniteRotation(bool state);
	void startTranslation(float speed, double time);
	void startTextureRectAnimation();

	void actualize(double time);
	void draw(sf::RenderWindow* window);
	void startAnimation();
	void stopAnimation();
	void restartAnimation();
	void setRepeatAnimation(bool state);
};