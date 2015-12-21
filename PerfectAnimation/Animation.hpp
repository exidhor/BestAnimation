#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <map>
#include <vector>
#include "Frame.hpp"
#include "TimeAnim.hpp"
#include "TokenActualizationSituation.hpp"

// CHECKED

/**
Tableau circulaire de Frame qui s'actualise
represente un etat (ex : Personnage qui cours, personnage a l'arret, ...)
*/
class Animation
{
private:
	std::vector<Frame*> m_frames;

	unsigned int m_indiceCurrentTexture;
	TimeAnim m_timerAnim;

public:
	Animation(std::vector<Frame*> v_ptr_textures);

	void restart();
	
	TokenActualizationSituation actualize(double time); // return true if it return to indice 0
	sf::Texture* getActualTexture();
	bool increaseIndice();
};