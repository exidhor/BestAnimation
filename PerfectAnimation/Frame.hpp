#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <map>
#include <vector>

// CHECKED

/**
Association d'une texture avec son temps d'affichage
*/
class Frame
{
private:
	sf::Texture* m_texture;
	double m_timeDispay;
public:
	Frame(sf::Texture* ptr_texture, double timeDispay);

	sf::Texture* getTexturePtr();
	double getTimeDisplay();
};