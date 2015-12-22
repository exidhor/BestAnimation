#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "LinearTransformation.hpp"
#include "TimeAnim.hpp"

class TranslationTransformation : public LinearTransformation
{
private:
	virtual void placeSpriteToTheEndOfTransformation();
	virtual void doTheTransformation(sf::Vector2f const& deplacement);
public:
	TranslationTransformation(sf::Sprite* spriteTarget);
};