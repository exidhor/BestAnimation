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
	bool m_endDeterminedByAngle;
public:
	RotationTransformation();

	void rotateByTime(float speed, double time);
	void rotateByAngle(float speed, float finalAngle);

	virtual bool actualize(double time);
};