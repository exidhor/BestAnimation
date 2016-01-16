#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "TextureContainer.hpp"

class TextureArray : public TextureContainer
{
private:
	std::vector <std::vector <sf::Texture*> > m_textureArray;
public:
	TextureArray(std::vector <std::vector <sf::Texture*> > textureArray, double timePerFrame);

	sf::Texture* getPtrTexture(int x, int y);
	unsigned int getSize(int x);
};