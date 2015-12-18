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
		m_timeLeft = m_timeFullDisplay;
		return true;
	}
	return false;
}

void TimeAnim::restart()
{
	m_timeLeft = m_timeFullDisplay;
}

void TimeAnim::setTime(double time)
{
	m_timeFullDisplay = time;
	m_timeLeft = m_timeFullDisplay;
}