#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <map>
#include <vector>
#include "Transformation.hpp"

class RotationTransformation : public Transformation
{
private:
	float m_finalAngle;
	float m_angleDegreeAdvancement;
public:
	RotationTransformation(sf::Sprite* spriteTarget);

	void initRotateByTime(float speed, double time);
	void initRotateByAngle(float speed, float finalAngle);
	bool endOfRotation(float & angleRotation, bool speedUpperThanZero);

	virtual bool actualize(double time);
};