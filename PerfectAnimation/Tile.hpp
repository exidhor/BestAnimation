#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>

class Tile
{
private:
	sf::Vector2f m_sizeOfOneTexture;
	sf::Texture* m_tile;
	std::vector <std::vector <double> > m_timeDisplay;
	sf::Vector2i m_indexCurrentTextureRect;
public:
	Tile(unsigned int numberFramePerLine, unsigned int numberFramePerCulumn,
		sf::Texture* tile, std::vector <std::vector <double> > timeDisplay);

	bool goToTheNextFrame();
	void goToTheLine(unsigned int indexCulumn);

	sf::Texture* getTexture();
	sf::IntRect getTextureRect();
};