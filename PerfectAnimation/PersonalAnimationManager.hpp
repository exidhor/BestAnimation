#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
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
	std::vector<Animation*> m_animations;
	bool m_isRepeated;
	bool m_isStarted;
	sf::Sprite m_sprite;
	int m_currentKey; //attend une enum 

public:
	PersonalAnimationManager(std::vector <Animation*> animations);

	void setIsRepeated(bool state);
	void start();
	void stop();
	void restart();
	void draw(sf::RenderWindow* ptr_window);
	void actualize(double time);

	void setPosition(sf::Vector2f const& position);
	void setPosition(float abs, float ord);
	void setStateAnimation(int key);
	
	sf::Vector2f getPosition() const;
	sf::Texture* getCurrentTexture();

	sf::Sprite* getSprite();
};