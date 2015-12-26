#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <map>

class TextureLoader
{
private:
	std::map <std::string, std::vector <std::vector <sf::Texture*> > > m_textureFrames;
	std::map <std::string, sf::Texture> m_textures;
public:
	// TO DO
};