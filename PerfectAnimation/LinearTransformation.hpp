#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Transformation.hpp"
#include "TimeAnim.hpp"

class LinearTransformation : public Transformation
{
private:
	virtual sf::Vector2f getPositionForTransformation();
	virtual void placeSpriteToTheEndOfTransformation();
	virtual void doTheTransformation(sf::Vector2f const& deplacement);

protected:
	sf::Vector2f m_targetPoint;
	float m_speedOrd;
	TimeAnim m_time;
	bool m_isDeterminedByTime;

public:
	LinearTransformation(sf::Sprite* targetSprite);

	virtual bool actualize(double time);
	void initByTargetPoint(double time, sf::Vector2f const& targetPoint);
	void initBySpeed(double time, sf::Vector2f const& speedPerSecond);
};