#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

// CHECKED sauf le systeme des cles et donc des gestions des differentes
// animations des differents etats

/**
Gere l'ensemble des animations li� a un element
Permet de lancer ou de boucler l'animation
Les differentes anim sont stock�s dans un vector qu'il faut
manipuler a l'aide d'une enum faite pour chaque element
*/
class PersonalAnimationManager
{
protected: 
	sf::Sprite m_sprite;
	bool m_isStarted;
	bool m_isRepeated;
public:
	PersonalAnimationManager();
	
	virtual void restart();
	virtual void actualize(double time) = 0;
	virtual void setStateAnimation(int key) = 0;
	virtual sf::Texture* getCurrentTexture() = 0;

	void start();
	void stop();
	void draw(sf::RenderWindow* ptr_window);

	void setIsRepeated(bool state);
	void setPosition(sf::Vector2f const& position);
	void setPosition(float abs, float ord);
	
	sf::Vector2f getPosition();

	sf::Sprite* getSprite();
};