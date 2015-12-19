#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>

// CHECKED

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
	void restart(double newTimeDisplay); // restart with the newTime for timeDisplay
	void restart(); //restart with the actual timeDisplay
	void softRestart(); //restart with substracting the old timeLeft

	void setTime(double time);
	double getTimeDisplay();
	double getTimeLeft();
};