#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "TextureContainer.hpp"

class Tile : public TextureContainer
{
private:
	sf::Vector2f m_sizeOfOneTexture;
	sf::Texture* m_tile;
	sf::Vector2i m_numberOfTextures;

public:
	Tile(sf::Texture* tile, double timePerFrame, sf::Vector2i numberOfTextures);

	sf::Vector2f getSizeOfOneTexture();
	sf::Vector2i getNumberOfTexures();
	sf::Texture* getPtrTexture();
};