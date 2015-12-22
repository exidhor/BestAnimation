#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "LinearTransformation.hpp"
#include "TimeAnim.hpp"

/*
	Représente une animation en changeant le rectangle d'affichage de la texture
	( setTextureRect(sf::FloatRect) )
*/
class ResizeRectTransformation : public LinearTransformation
{
private:
	virtual sf::Vector2f getPositionForTransformation();
	virtual void placeSpriteToTheEndOfTransformation();
	virtual void doTheTransformation(sf::Vector2f const& deplacement);
public:
	ResizeRectTransformation(sf::Sprite* targetSprite);
};