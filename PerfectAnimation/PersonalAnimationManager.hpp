#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include "TimeAnim.hpp"
#include "Animation.hpp"

// CHECKED sauf le systeme des cles et donc des gestions des differentes
// animations des differents etats

/**
Gere l'ensemble des animations lié a un element
Permet de lancer ou de boucler l'animation
Les differentes anim sont stockés dans un vector qu'il faut
manipuler a l'aide d'une enum faite pour chaque element
*/
class PersonalAnimationManager
{
private: 
	sf::Sprite m_sprite;
	TimeAnim m_timeAnim;
	Animation* m_animation;
	bool m_isStarted;
	bool m_isRepeated;

public:
	PersonalAnimationManager(Animation* animation);
	
	void restart();
	void softRestart();
	void actualize(double timeSpent);
	void start();
	void stop();
	void drawSprite(sf::RenderWindow* ptr_window);

	void setStateAnimation(int key);
	void setIsRepeated(bool state);
	void setPositionSprite(sf::Vector2f const& position);
	void setPositionSprite(float abs, float ord);
	void synchroTimeAnimWithFrame();

	sf::Vector2f getPositionSprite();
	sf::Sprite* getSprite();
};