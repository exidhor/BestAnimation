#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>

/**
Minuteur pour gerer l'aternance des textures dans Frame
*/
class TimeAnim
{
private:
	double m_timeFullDisplay;
	double m_timeLeft;
public:
	TimeAnim(double newtimeFullDisplay);
	bool removeTime(double timeToRemove); //return true if it reach 0
	void restart();

	void setTime(double time);
};