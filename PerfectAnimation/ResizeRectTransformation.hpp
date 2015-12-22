#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Transformation.hpp"
#include "TimeAnim.hpp"

/*
	Représente une animation en changeant le rectangle d'affichage de la texture
	( setTextureRect(sf::FloatRect) )
*/
class ResizeRectTransformation : public Transformation
{
private:
	sf::Vector2f m_targetPositionRect;
	TimeAnim m_time;
	float m_speedOrd;
public:
	ResizeRectTransformation(sf::Sprite* targetSprite);

	virtual bool actualize(double time);

	void initResizeByTargetPoint(double time, sf::Vector2f const& targetPoint);
	void initResizeBySpeed(double time, sf::Vector2f const& speedPerSecond);
};