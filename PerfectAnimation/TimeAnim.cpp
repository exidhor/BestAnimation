#include "TimeAnim.hpp"

TimeAnim::TimeAnim(double newtimeFullDisplay)
{
	m_timeFullDisplay = newtimeFullDisplay;
	m_timeLeft = m_timeFullDisplay;
}

bool TimeAnim::removeTime(double timeToRemove)
{
	m_timeLeft -= timeToRemove;
	if (m_timeLeft <= 0)
	{
		return true;
	}
	return false;
}

void TimeAnim::restart(double newTimeDisplay)
{
	m_timeLeft = newTimeDisplay;
}

void TimeAnim::setTime(double time)
{
	m_timeFullDisplay = time;
	m_timeLeft = m_timeFullDisplay;
}

double TimeAnim::getTimeDisplay()
{
	return m_timeFullDisplay;
}

void TimeAnim::restart()
{
	m_timeLeft = m_timeFullDisplay;
}

void TimeAnim::softRestart()
{
	m_timeLeft += m_timeFullDisplay;
	if (m_timeLeft <= 0)
	{
		std::cerr << "Error in the timer, timer set value <= 0" << std::endl;
	}
}

double TimeAnim::getTimeLeft()
{
	return m_timeLeft;
}