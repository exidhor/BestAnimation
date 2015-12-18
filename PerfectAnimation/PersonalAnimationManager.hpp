#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <map>
#include <vector>
#include "Animation.hpp"


/**
Gere l'ensemble des animations li� a un element
Permet de lancer ou de boucler l'animation
Les differentes anim sont stock�s dans un vector qu'il faut
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
	void draw(sf::RenderWindow* ptr_window);


	void setPosition(sf::Vector2f const& position);
	void setPosition(int x, int y);
	void setStateAnimation(int key);
	
	sf::Vector2f getPosition() const;
	sf::Texture* getCurrentTexture();

	sf::Sprite* getSprite();
};