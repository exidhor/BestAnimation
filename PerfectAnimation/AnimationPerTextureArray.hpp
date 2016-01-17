#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "TextureArray.hpp"
#include "Animation.hpp"

class AnimationPerTextureArray : public Animation
{
private:
	TextureArray* m_textureArray;

public:
	AnimationPerTextureArray(TextureArray* textureArray);
	AnimationPerTextureArray(sf::Sprite* targetSprite, TextureArray* textureArray);
	AnimationPerTextureArray(std::vector <std::vector <sf::Texture*> > textures, double timePerFrame);

	virtual void setActualTexture();

	virtual unsigned int getSizeCurrentLine();
	virtual double getActualTimeFrame();
};