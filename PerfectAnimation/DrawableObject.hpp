#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <map>
#include <vector>
#include "PersonalAnimationManager.hpp"

class DrawableObject
{
private:
	PersonalAnimationManager m_personalAnimationManager;

	bool m_rotationOn;
	bool m_rotationIsInfinite;
	TimeAnim m_timeRotation;

	bool translationOn;
	bool m_translationIsInfinite;
	TimeAnim m_timeTranslation;

public:
	DrawableObject(std::vector <Animation*> animations);

	sf::Vector2f getPosition() const;

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f & position);

	void startRotation(double time, float speedPerSecond);
	void startTranslation(double time, float speed);
	void startTextureRectAnimation();

	void actualize(double time);
	void draw(sf::RenderWindow* window);
};