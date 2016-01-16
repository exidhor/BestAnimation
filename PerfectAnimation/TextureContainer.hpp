#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>

class TextureContainer
{
protected:
	double m_timePerFrame;
public:
	TextureContainer(double timePerFrame);

	double getTimePerFrame();
};